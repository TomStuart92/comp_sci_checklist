public class Knapsack {
  static int max(int a, int b) {
    return (a > b) ? a : b;
  }

  static int knapSackRecursive(int maxWeight, int weights[], int values[], int numberOfItems) {
    if (numberOfItems == 0 || maxWeight == 0) {
      return 0;
    }
    // if weight of last item is greater than maxWeight we can recurse on prefix.
    if(weights[numberOfItems - 1] > maxWeight) {
      return knapSackRecursive(maxWeight, weights, values, numberOfItems - 1);
    }
    // else we want two return max value from either including or excluding nth item.
    else {
      int include = values[numberOfItems - 1] + knapSackRecursive(maxWeight - weights[numberOfItems - 1], weights, values, numberOfItems - 1);
      int exclude = knapSackRecursive(maxWeight, weights, values, numberOfItems - 1);
      return max(include, exclude);
    }
  }

  static int knapSackDP(int maxWeight, int weights[], int values[], int numberOfItems) {
    int[][] V = new int[numberOfItems + 1][maxWeight + 1];
    for(int col = 0; col <= maxWeight; col++) {
      // if maxWeight = 0, we can't carry anything so initialize those columns to 0.
      V[0][col] = 0;
    }

    for(int row = 0; row <= numberOfItems; row++) {
      // if no items nothing to carry anything so initialize those rows to 0.
      V[row][0] = 0;
    }

    for(int item = 1; item <= numberOfItems; item++) {
      for(int weight = 1; weight <= maxWeight; weight++) {
        if(weights[item - 1] <= weight) {
          V[item][weight] = max(
              values[item - 1] + V[item - 1][weight - weights[item - 1]],  // include item
              V[item - 1][weight]     // exclude item
          );
        } else {
          V[item][weight] = V[item - 1][weight];  // can't fit item.
        }
      }
    }

    return V[numberOfItems][maxWeight];
  }
}
