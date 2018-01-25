import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class QueueWithLinkedListTest {
    @Test
    void newQueueShouldHaveSizeZero() {
        QueueWithLinkedList test = new QueueWithLinkedList();
        assertEquals(0, test.size());
    }

    @Test
    void newQueueShouldBeEmpty() {
        QueueWithLinkedList test = new QueueWithLinkedList();
        assertEquals(true, test.isEmpty());
    }

    @Test
    void shouldBeAbleToEnqueue() {
        QueueWithLinkedList test = new QueueWithLinkedList();
        test.enqueue(1);
        assertEquals(1, test.size());
    }

    @Test
    void shouldBeAbleToDequeue() {
        QueueWithLinkedList test = new QueueWithLinkedList();
        test.enqueue(1);
        assertEquals(1, test.dequeue());
        assertEquals(0, test.size());
    }
}