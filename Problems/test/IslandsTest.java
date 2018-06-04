import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class IslandsTest {

    @Test
    void countIslandsShouldReturnZeroOn0DArray() {
        int M[][]=  new int[][] {{}};
        assertEquals(0, Islands.countIslands(M));
    }

    @Test
    void countIslandsShouldReturnZeroOnZeroArray() {
        int M[][]=  new int[][] {{0}};
        assertEquals(0, Islands.countIslands(M));
    }

    @Test
    void countIslandsShouldReturnZeroOnOneArray() {
        int M[][]=  new int[][] {{1}};
        assertEquals(1, Islands.countIslands(M));
    }

    @Test
    void countIslandsShouldReturnIslandCount() {
        int M[][]=  new int[][] {{1, 1, 0, 0, 0},
                {0, 1, 0, 0, 1},
                {1, 0, 0, 1, 1},
                {0, 0, 0, 0, 0},
                {1, 0, 1, 0, 1}};
        assertEquals(5, Islands.countIslands(M));
    };
}