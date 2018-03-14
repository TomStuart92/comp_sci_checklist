import java.util.HashMap;

// Given an array of numbers, return whether any two sums to K.

// For example, given [10, 15, 3, 7] and K of 17, return true since 10 + 7 is 17.


public class TwoNumberTarget {
  private final int[] numbers;

  private TwoNumberTarget(int[] numbers) {
    this.numbers = numbers;
  }

  private boolean containsSum(int target) {
    HashMap<Integer, Integer> results = new HashMap<>();
    for (int number : numbers) {
      if (results.containsKey(target - number)) {
        return true;
      }
      results.put(number, number);
    }
    return false;
  }

  public static void main(String args[]) {
    int[] numbers = {10, 15, 3, 7};
    TwoNumberTarget test = new TwoNumberTarget(numbers);
    System.out.println("contains 17 is true: " + test.containsSum(17));
    System.out.println("contains 12 is false: " + test.containsSum(12));
  }
}