import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class EditDistanceTest {

  @Test
  void minShouldReturnMin() {
    assertEquals(3, EditDistance.min("abc", "def"));
  }

  @Test
  void minShouldWorkForEmptyString() {
    assertEquals(0, EditDistance.min("", ""));
  }

  @Test
  void minShouldWorkForDifferentLengthStrings() {
    assertEquals(4, EditDistance.min("abc", "defg"));
  }
}