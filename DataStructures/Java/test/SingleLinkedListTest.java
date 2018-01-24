import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

class SingleLinkedListTest {
    @Test
    void newLLShouldHaveSizeZero() {
        SingleLinkedList test = new SingleLinkedList();
        assertEquals(0, test.size());
    }

    @Test
    void newLLShouldBeEmpty() {
        SingleLinkedList test = new SingleLinkedList();
        assertEquals(true, test.isEmpty());
    }

    @Test
    void shouldBeAbleToAddANewNodeToLL() {
        SingleLinkedList test = new SingleLinkedList();
        test.pushFront(1);
        assertEquals(false, test.isEmpty());
        assertEquals(1, test.size());
        assertEquals(1, test.front());
        assertEquals(1, test.back());
    }

    @Test
    void shouldBeAbleToPopANodeFromFrontOfLL() {
        SingleLinkedList test = new SingleLinkedList();
        test.pushFront(1);
        int poppedValue = test.popFront();
        assertEquals(1, poppedValue);
        assertEquals(true, test.isEmpty());
        assertEquals(0, test.size());
    }

    @Test
    void shouldBeAbleToAddANodeToEndOfLL() {
        SingleLinkedList test = new SingleLinkedList();
        test.pushFront(1);
        test.pushBack(2);
        assertEquals(2, test.size());
        assertEquals(1, test.front());
        assertEquals(2, test.back());
    }

    @Test
    void shouldBeAbleToPopANodeFromEndOfLL() {
        SingleLinkedList test = new SingleLinkedList();
        test.pushFront(1);
        test.pushBack(2);
        int popped = test.popBack();
        assertEquals(2, popped);
        assertEquals(1, test.size());
        assertEquals(1, test.front());
        assertEquals(1, test.back());
    }

    @Test
    void popBackShouldWorkWithOnlyOneNode() {
        SingleLinkedList test = new SingleLinkedList();
        test.pushFront(1);
        int popped = test.popBack();
        assertEquals(1, popped);
        assertEquals(0, test.size());
    }

    @Test
    void shouldBeAbleToInsertANode() {
        SingleLinkedList test = new SingleLinkedList();
        test.pushFront(1);
        test.pushFront(2);
        test.insertAt(1, 3);
        assertEquals(3, test.size());
        assertEquals(2, test.front());
        assertEquals(1, test.back());
    }

    @Test
    void shouldBeAbleToRemoveANode() {
        SingleLinkedList test = new SingleLinkedList();
        test.pushFront(1);
        test.pushFront(2);
        test.erase(1);
        assertEquals(1, test.size());
        assertEquals(2, test.front());
        assertEquals(2, test.back());
    }

    @Test
    void shouldBeAbleToGetValueOfANode() {
        SingleLinkedList test = new SingleLinkedList();
        test.pushFront(1);
        test.pushFront(2);
        int value = test.valueAt(0);
        assertEquals(2, value);
    }

    @Test
    void shouldBeAbleToGetValueOfNthNode() {
        SingleLinkedList test = new SingleLinkedList();
        test.pushFront(1);
        test.pushFront(2);
        test.pushFront(3);
        int value = test.valueNFromEnd(1);
        assertEquals(2, value);
    }

    @Test
    void shouldBeAbleToReverseList() {
        SingleLinkedList test = new SingleLinkedList();
        test.pushFront(1);
        test.pushFront(2);
        test.pushFront(3);
        test.reverse();
        assertEquals(1, test.front());
        int value = test.valueNFromEnd(1);
        assertEquals(2, value);
        assertEquals(3, test.back());
    }

    @Test
    void shouldBeAbleToRemoveAValue() {
        SingleLinkedList test = new SingleLinkedList();
        test.pushFront(1);
        test.pushFront(2);
        test.pushFront(3);
        test.removeValue(2);
        assertEquals(3, test.front());
        assertEquals(2, test.size());
        assertEquals(1, test.back());
    }


}