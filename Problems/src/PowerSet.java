import java.util.*;
// The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.
// For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

class PowerSet {
  private static Set<Set<Integer>> recursePowerSet(int count, Set<Integer> inSet, Set<Integer> remaining) {
    if(remaining.isEmpty()) {
      Set<Set<Integer>> result = new HashSet<>();
      result.add(inSet);
      return result;
    } else {
      Integer nextChoice = remaining.iterator().next();

      // recurse and exclude
      Set<Integer> excludeSet = new HashSet<>(inSet);
      Set<Integer> excludeRemaining = new HashSet<>(remaining);
      excludeRemaining.remove(nextChoice);
      Set<Set<Integer>> exclude = recursePowerSet(count + 1, excludeSet, excludeRemaining);

      // recurse and include
      Set<Integer> includeSet = new HashSet<>(inSet);
      Set<Integer> includeRemaining = new HashSet<>(remaining);
      includeRemaining.remove(nextChoice);
      includeSet.add(nextChoice);
      Set<Set<Integer>> include = recursePowerSet(count + 1, includeSet, includeRemaining);

      // combine and return
      Set<Set<Integer>> result = new HashSet<>();
      result.addAll(include);
      result.addAll(exclude);
      return result;
    }
   };

  static Set<Set<Integer>> compute(Set<Integer> set) {
    Set<Integer> emptySet = new HashSet<>();
    return recursePowerSet(0, emptySet, set);
  }
}