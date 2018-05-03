import org.junit.jupiter.api.Test;

import java.util.*;

import static org.junit.jupiter.api.Assertions.assertEquals;

class PowerSetTest {

  @Test
  void computeShouldReturnPowerSet() {
    List<Integer> numbers = Arrays.asList(1, 2, 3);
    Set<Integer> test = new HashSet<>(numbers);
    Set<Set<Integer>> result = PowerSet.compute(test);

    Set<Set<Integer>> expected = new HashSet<>();
    expected.add(new HashSet<>(Collections.emptyList()));
    expected.add(new HashSet<>(Collections.singletonList(1)));
    expected.add(new HashSet<>(Collections.singletonList(2)));
    expected.add(new HashSet<>(Collections.singletonList(3)));
    expected.add(new HashSet<>(Arrays.asList(1, 2)));
    expected.add(new HashSet<>(Arrays.asList(1, 3)));
    expected.add(new HashSet<>(Arrays.asList(2, 3)));
    expected.add(new HashSet<>(Arrays.asList(1, 2, 3)));

    assertEquals(expected, result);
  }

  @Test
  void computeShouldDealWithEmptySet() {
    Set<Integer> test = new HashSet<>(Collections.emptyList());
    Set<Set<Integer>> result = PowerSet.compute(test);

    Set<Set<Integer>> expected = new HashSet<>();
    expected.add(new HashSet<>(Collections.emptyList()));
    assertEquals(expected, result);
  }
}