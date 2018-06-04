import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class LongestSubsequenceTest {

  @Test
  void itShouldHandleAZeroLengthStrings() {
    String s1 = "";
    String s2 = "Hello";
    assertEquals(0, LongestSubsequence.lcs(s1, s2));
    assertEquals(0, LongestSubsequence.lcs(s2, s1));
  }

  @Test
  void itShouldHandleEmptyStrings() {
    String s1 = "";
    String s2 = "";
    assertEquals(0, LongestSubsequence.lcs(s1, s2));
    assertEquals(0, LongestSubsequence.lcs(s2, s1));
  }

  @Test
  void itShouldHandleTheSameString() {
    String s1 = "hello";
    assertEquals(s1.length(), LongestSubsequence.lcs(s1, s1));
    assertEquals(s1.length(), LongestSubsequence.lcs(s1, s1));
  }

  @Test
  void itShouldHandleDifferentString() {
    String s1 = "AGGTAB";
    String s2 = "GXTXAYB";
    assertEquals(4, LongestSubsequence.lcs(s1, s2));
    assertEquals(4, LongestSubsequence.lcs(s1, s2));
  }
}