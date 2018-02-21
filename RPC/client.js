// constansts
const PROTO_PATH = __dirname + '/route_guide.proto';
const DB_PATH = __dirname + '/routeGuideDB.json';
const COORD_FACTOR = 1e7;

// modules
const fs = require('fs');
const path = require('path');
const grpc = require('grpc');

// globals
const routeguide = grpc.load(PROTO_PATH).routeguide;
const client = new routeguide.RouteGuide('localhost:50051', grpc.credentials.createInsecure());
let featureCache = [];

class Feature {
  constructor({ name, location = {} }) {
    this.name = name;
    this.location = location;
  }
}

class Point {
  constructor({ longitude, latitude }) {
    this.longitude = longitude;
    this.latitude = latitude;
  }
}

function featureCallback(error, feature) {
  if (error) 
    throw error;
  if (feature.name === '') {
    console.log('Found no feature at ' +
    feature.location.latitude/COORD_FACTOR + ', ' +
    feature.location.longitude/COORD_FACTOR);
  } else {
    console.log('Found feature called "' + feature.name + '" at ' +
    feature.location.latitude/COORD_FACTOR + ', ' +
    feature.location.longitude/COORD_FACTOR);
  }
}

function routeCallback(error, stats) {
  if (error) {
    throw error;
  }
  console.log('Finished trip with', stats.pointCount, 'points');
  console.log('Passed', stats.featureCount, 'features');
  console.log('Travelled', stats.distance, 'meters');
  console.log('It took', stats.elapsedTime, 'seconds');
}


async function runGetFeature() {
  var point1 = {
    latitude: 409146138,
    longitude: -746188906
  };
  var point2 = {
    latitude: 0,
    longitude: 0
  };
  await client.getFeature(point1, featureCallback);
  await client.getFeature(point2, featureCallback);
}

async function runListFeature() {
    var rectangle = {
      lo: {
        latitude: 400000000,
        longitude: -750000000
      },
      hi: {
        latitude: 420000000,
        longitude: -730000000
      }
    };
    console.log('Looking for features between 40, -75 and 42, -73');
    var call = client.listFeatures(rectangle);
    call.on('data', feature => featureCallback(null, feature));
    call.on('err', e => featureCallback(e, null));
}

async function runRecordRoute(numPoints) {
  const call = client.recordRoute(routeCallback);
  for(let i = 0; i < numPoints; i += 1) {
    setTimeout(() => {
      const randomFeature = featureCache[Math.floor(Math.random() * featureCache.length)];
      console.log('Visiting point ' + randomFeature.location.latitude/COORD_FACTOR + ', ' + randomFeature.location.longitude/COORD_FACTOR);
      call.write({
        latitude: randomFeature.location.latitude,
        longitude: randomFeature.location.longitude
      });
    }, i * 1000 * Math.random());
  }
  setTimeout(() => call.end(), numPoints * 1100);
}

async function runRouteChat(notes) {
  const call = client.routeChat();
  call.on('data', note =>  console.log('Got message "' + note.message + '" at ' + note.location.latitude + ', ' + note.location.longitude));
  for (var i = 0; i < notes.length; i++) {
    var note = notes[i];
    console.log('Sending message "' + note.message + '" at ' +
        note.location.latitude + ', ' + note.location.longitude);
    call.write(note);
  }
  call.end();
}

const notes = [{
  location: {
    latitude: 0,
    longitude: 0
  },
  message: 'First message'
}, {
  location: {
    latitude: 0,
    longitude: 1
  },
  message: 'Second message'
}, {
  location: {
    latitude: 1,
    longitude: 0
  },
  message: 'Third message'
}, {
  location: {
    latitude: 0,
    longitude: 0
  },
  message: 'Fourth message'
}];

(async function main() {
  fs.readFile(DB_PATH, async function(err, data) {
    if (err) throw err;

    featureCache = JSON.parse(data).map(data => {
      point = new Point({ longitude: data.location.longitude, latitude: data.location.latitude });
      return new Feature({ name: data.name, location: point });
    })

    // await runGetFeature();
    await runListFeature();
    // await runRecordRoute(10);
    // await runRouteChat(notes);
  });
})();


