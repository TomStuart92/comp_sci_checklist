import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BinarySearchTest {
    @Test
    void shouldReturnIndexOfItem() {
        int[] testArray = {1, 2, 3, 4, 5};
        assertEquals(2, BinarySearch.search(testArray, 3));
    }

    @Test
    void shouldReturnNegativeOneIfNotFound() {
        int[] testArray = {1, 2, 3, 4, 5};
        assertEquals(-1, BinarySearch.search(testArray, 20));
    }

    @Test
    void shouldReturnIndexOfItemRecursively() {
        int[] testArray = {1, 2, 3, 4, 5};
        assertEquals(2, BinarySearch.recursiveBinarySearch(testArray, 3));
    }

    @Test
    void shouldReturnNegativeOneIfNotFoundRecursively() {
        int[] testArray = {1, 2, 3, 4, 5};
        assertEquals(-1, BinarySearch.recursiveBinarySearch(testArray, 20));
    }
}