import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;

class VectorTest {
    @Test
    void newVectorShouldHaveSizeZero() {
        Vector test = new Vector();
        assertEquals(0, test.size());
    }

    @Test
    void newVectorShouldBeEmpty() {
        Vector test = new Vector();
        assertEquals(true, test.isEmpty());
    }

    @Test
    void newVectorShouldHaveCapacityTwo() {
        Vector test = new Vector();
        assertEquals(2, test.capacity());
    }

    @Test
    void shouldBeAbleToAddItemToVector() {
        Vector test = new Vector();
        test.push(1);
        assertEquals(1, test.size());
        assertEquals(1, test.at(0));
        assertEquals(false, test.isEmpty());
    }

    @Test
    void shouldBeAbleToAddItemToFrontOfVector() {
        Vector test = new Vector();
        test.push(1);
        test.prepend(2);
        assertEquals(2, test.size());
        assertEquals(2, test.at(0));
        assertEquals(1, test.at(1));
    }

    @Test
    void vectorShouldResizeOnceItIsFull() {
        Vector test = new Vector();
        test.push(1);
        test.push(2);
        assertEquals(test.size(), test.capacity());
        test.push(3);
        assertNotEquals(test.size(), test.capacity());
    }

    @Test
    void shouldBeAbleToInsertItemAnywhereInVector() {
        Vector test = new Vector();
        test.push(1);
        test.push(2);
        test.insert(1,3);
        assertEquals(3, test.size());
        assertEquals(1, test.at(0));
        assertEquals(3, test.at(1));
        assertEquals(2, test.at(2));
    }

    @Test
    void shouldBeAbleToPopFromVector() {
        Vector test = new Vector();
        test.push(1);
        int popped = test.pop();
        assertEquals(1, popped);
        assertEquals(true, test.isEmpty());
    }

    @Test
    void shouldBeAbleToDeleteFromVector() {
        Vector test = new Vector();
        test.push(1);
        test.push(2);
        test.push(3);
        test.delete(1);
        assertEquals(2, test.size());
        assertEquals(1, test.at(0));
        assertEquals(3, test.at(1));
    }

    @Test
    void shouldBeAbleToFindItemInVector() {
        Vector test = new Vector();
        test.push(1);
        test.push(2);
        assertEquals(1, test.find(2));
    }

    @Test
    void shouldBeAbleToRemoveItemFromVector() {
        Vector test = new Vector();
        test.push(1);
        test.push(2);
        test.remove(2);
        assertEquals(1, test.size());
        assertEquals(1, test.at(0));
    }
}