// Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

// For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

class LowestInt {
  private int lowest(int arr[]) {
    if (arr.length <= 0) {
      throw new Error("Array must have length > 0");
    }
    int lowest = arr[0];
    for (int value : arr) {
      System.out.println("checking: " + value);
      if (value < lowest && value > 0) {
        lowest = value;
      }
      System.out.println("lowest: " + lowest);
    }
    return lowest - 1;
  }
  public static void main(String[] args) {
    LowestInt test = new LowestInt();
    int[] arr1 = {3, 4, -1, 1};
    int[] arr2 = {1, 2, 0};
    System.out.println("2: " + test.lowest(arr1));
    System.out.println("3: " + test.lowest(arr2));
  }
}