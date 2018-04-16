import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ThreeWaySortTest {

    @Test
    void itShouldSortArray() {
        ThreeWaySort.colors[] array = {ThreeWaySort.colors.WHITE, ThreeWaySort.colors.RED,ThreeWaySort.colors.RED, ThreeWaySort.colors.RED, ThreeWaySort.colors.BLUE, ThreeWaySort.colors.RED, ThreeWaySort.colors.WHITE};
        ThreeWaySort.colors[] expected = {ThreeWaySort.colors.RED, ThreeWaySort.colors.RED,ThreeWaySort.colors.RED, ThreeWaySort.colors.RED, ThreeWaySort.colors.WHITE, ThreeWaySort.colors.WHITE, ThreeWaySort.colors.BLUE};
        ThreeWaySort.colors[] result = ThreeWaySort.threeWaySort(array);

        for(int i = 0; i< expected.length; i++) {
            assertEquals(expected[i], result[i], "Error at index: " + i);
        }
    }
}