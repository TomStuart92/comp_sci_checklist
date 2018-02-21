// constants
const PROTO_PATH = __dirname + '/route_guide.proto';
const DB_PATH = __dirname + '/routeGuideDB.json';
const COORD_FACTOR = 1e7;

// modules
const fs = require('fs');
const path = require('path');
const grpc = require('grpc');

// globals
const routeguide = grpc.load(PROTO_PATH).routeguide;
let featureCache = [];
let routeNotes = {};

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
  equals(point) {
    if(!(point instanceof Point))
      throw new TypeError();
    return point.latitude === this.latitude && point.longitude === this.longitude;
  }
  toString() {
    return this.latitude + ' ' + this.longitude;
  }
}

class Rectangle {
  constructor({ lo, hi }) {
    this.lo = lo;
    this.hi = hi;
    this.left = Math.min(lo.longitude, hi.longitude);
    this.right = Math.max(lo.longitude, hi.longitude);
    this.top = Math.max(lo.latitude, hi.latitude);
    this.bottom = Math.min(lo.latitude, hi.latitude);
  }

  includes(point) {
    return point.longitude >= this.left && 
      point.longitude <= this.right && 
      point.latitude >= this.bottom && 
      point.latitude <= this.top
  }
}

// get a feature at the given point or create one if none exists;
function checkFeature(point) {
  const featureMatch = featureCache.find(feature => feature.location.equals(point));
  if(featureMatch)
    return featureMatch;
  return new Feature({ name: '', location: point })
}

function getFeature(call, callback) {
  const point = new Point(call.request);
  return callback(null, checkFeature(point));
}

// get all features in rectangle, and stream back;
function listFeatures(call) {
  const rectangle = new Rectangle({ hi: call.request.hi, lo: call.request.lo });
  featureCache.forEach(feature => {
    if (rectangle.includes(feature.location)) {
      call.write(feature);
    }
  })
  call.end();
}

// stub to calculate distance bw two points
function getDistance(start, end) {
  return 10;
}

// accepts a stream of points and returns a route record;
function recordRoute(call, callback) {
  let pointCount = 0;
  let featureCount = 0;
  let distance = 0;
  let previous = null;
  
  const startTime = process.hrtime();

  call.on('data', data => {
    const point = new Point(data);
    pointCount += 1;

    if(checkFeature(point).name !== '') 
      featureCount += 1;

    if(previous != null) {
      distance += getDistance(previous, point);
    }
    previous = point;
  })

  call.on('end', () => {
    callback(null, { pointCount, featureCount, distance, elapsedTime: process.hrtime(startTime)[0] })
  })
}

function routeChat(call) {
  call.on('data', (note) => {
    const point = new Point(note.location);
    const key = point.toString();
    routeNotes[key] = call.note;

    // respond with note;
    call.write(note);
  })
  // hang up when other end hangs up;
  call.on('end', call.end);
}

(() => {
  const server = new grpc.Server();

  //bind service handlers
  server.addService(routeguide.RouteGuide.service, {
    getFeature: getFeature,
    listFeatures: listFeatures,
    recordRoute: recordRoute,
    routeChat: routeChat
  });

  //start server
  server.bind('0.0.0.0:50051', grpc.ServerCredentials.createInsecure());

  //load and parse seed data
  const file = fs.readFileSync(DB_PATH);
  featureCache = JSON.parse(file).map(data => {
    point = new Point({ longitude: data.location.longitude, latitude: data.location.latitude });
    return new Feature({ name: data.name, location: point });
  })

  //start server
  server.start();
  console.log('Running on Port 50051');
})()