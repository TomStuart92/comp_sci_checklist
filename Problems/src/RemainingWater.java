// You are given an array of non-negative integers that represents a two-dimensional elevation map where each element is unit-width wall and the integer is the height. Suppose it will rain and all spots between two walls get filled up.
// Compute how many units of water remain trapped on the map in O(N) time and O(1) space.
// For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.
// Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the second, and 3 in the fourth index (we cannot hold 5 since it would run off to the left), so we can trap 8 units of water.

class RemainingWater {
    public static int remainingWater(int[] levels) {

      int length = levels.length;

      if (length == 0) {
          return 0;
      }
      int left[] = new int[length];
      int right[] = new int[length];

      int water = 0;

      // Fill left array
      left[0] = levels[0];
      for (int i = 1; i < length; i++)
          left[i] = Math.max(left[i-1], levels[i]);

      // Fill right array
      right[length-1] = levels[length-1];
      for (int i = length-2; i >= 0; i--)
          right[i] = Math.max(right[i+1], levels[i]);

      for (int i = 0; i < length; i++)
          water += Math.min(left[i],right[i]) - levels[i];

      return water;
  }
}