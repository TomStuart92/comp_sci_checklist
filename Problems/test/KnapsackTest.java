import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class KnapsackTest {

  @Test
  void maxShouldReturnTheMaxOfTwoInts() {
    assertEquals(2, Knapsack.max(1,2));
    assertEquals(1, Knapsack.max(0,1));
    assertEquals(0, Knapsack.max(-1,0));
    assertEquals(-1 , Knapsack.max(-2,-1));
  }

  @Test
  void knapSackRecursiveShouldReturnZeroForEdgeCases() {
    assertEquals(0, Knapsack.knapSackRecursive(0, new int[]{1, 2, 3}, new int[]{4,5,6}, 3));
    assertEquals(0, Knapsack.knapSackRecursive(10, new int[0], new int[0], 0));
  }

  @Test
  void knapSackRecursiveShouldReturnOptimalValueForKnapsack() {
    assertEquals(220, Knapsack.knapSackRecursive(50, new int[]{10, 20, 30}, new int[]{60, 100, 120}, 3));
  }

  @Test
  void knapsackDPShouldReturnZeroForEdgeCases() {
    assertEquals(0, Knapsack.knapSackDP(0, new int[]{1, 2, 3}, new int[]{4,5,6}, 3));
    assertEquals(0, Knapsack.knapSackDP(10, new int[0], new int[0], 0));
  }

  @Test
  void knapsackDPShouldReturnOptimalValueForKnapsack() {
    assertEquals(220, Knapsack.knapSackDP(50, new int[]{10, 20, 30}, new int[]{60, 100, 120}, 3));
  }
}