import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class StackTest {

    @Test
    void newStackShouldBeEmpty() {
        Stack test = new Stack(5);
        assertEquals(true, test.isEmpty());
    }

    @Test
    void newStackShouldHaveSizeZero() {
        Stack test = new Stack(5);
        assertEquals(0, test.size());
    }

    @Test
    void capacityShouldBeSetAtInitialization() {
        Stack test = new Stack(5);
        assertEquals(5, test.capacity());
    }

    @Test
    void newStackShouldNotBeFull() {
        Stack test = new Stack(5);
        assertEquals(false, test.isFull());
    }

    @Test
    void stackShouldBeAbleToPushItem() {
        Stack test = new Stack(5);
        test.push(1);
        assertEquals(1, test.size());
    }

    @Test
    void stackShouldBeAbleToGetTopItem() {
        Stack test = new Stack(5);
        test.push(1);
        assertEquals(1, test.top());
        assertEquals(1, test.size());
    }

    @Test
    void stackShouldBeAbleToRemoveItem() {
        Stack test = new Stack(5);
        test.push(1);
        assertEquals(1, test.pop());
        assertEquals(0, test.size());
        assertEquals(true, test.isEmpty());
    }


}