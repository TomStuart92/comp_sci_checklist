import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RemainingWaterTest {
    @Test
    void itShouldWorkInSimpleCase() {
        int[] levels = {2, 1, 2};
        assertEquals(1, RemainingWater.remainingWater(levels));
    }

    @Test
    void itShouldWorkInComplexCase() {
        int[] levels = {3, 0, 1, 3, 0, 5};
        assertEquals(8, RemainingWater.remainingWater(levels));
    }

    @Test
    void itShouldWorkInEdgeCase() {
        int[] levels = {};
        assertEquals(0, RemainingWater.remainingWater(levels));
    }

    @Test
    void itShouldWorkInSingleCase() {
        int[] levels = {1};
        assertEquals(0, RemainingWater.remainingWater(levels));
    }

    @Test
    void itShouldWorkInFlatCase() {
        int[] levels = {2,2,2};
        assertEquals(0, RemainingWater.remainingWater(levels));
    }

    @Test
    void itShouldWorkInUphillCase() {
        int[] levels = {2,3,4};
        assertEquals(0, RemainingWater.remainingWater(levels));
    }

    @Test
    void itShouldWorkInDownhillCase() {
        int[] levels = {4, 3, 2};
        assertEquals(0, RemainingWater.remainingWater(levels));
    }

}