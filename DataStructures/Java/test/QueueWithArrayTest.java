import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class QueueWithArrayTest {
    @Test
    void newQueueShouldHaveSizeZero() {
        QueueWithArray test = new QueueWithArray(5);
        assertEquals(0, test.size());
    }

    @Test
    void newQueueShouldBeEmpty() {
        QueueWithArray test = new QueueWithArray(5);
        assertEquals(true, test.isEmpty());
    }

    @Test
    void newQueueShouldNotBeFull() {
        QueueWithArray test = new QueueWithArray(5);
        assertEquals(false, test.isFull());
    }

    @Test
    void newQueueShouldHaveCapacity() {
        QueueWithArray test = new QueueWithArray(5);
        assertEquals(5, test.capacity());
    }

    @Test
    void shouldBeAbleToEnqueue() {
        QueueWithArray test = new QueueWithArray(5);
        test.enqueue(1);
        assertEquals(1, test.size());
    }

    @Test
    void shouldBeAbleToDequeue() {
        QueueWithArray test = new QueueWithArray(5);
        test.enqueue(1);
        assertEquals(1, test.dequeue());
        assertEquals(0, test.size());
    }

    @Test
    void shouldThrowOnFullEnqueue() {
        QueueWithArray test = new QueueWithArray(2);
        test.enqueue(1);
        Throwable exception = assertThrows(Error.class, () -> test.enqueue(1));
        assertEquals("Full Queue", exception.getMessage());
    }

    @Test
    void shouldThrowOnEmptyDequeue() {
        QueueWithArray test = new QueueWithArray(5);
        Throwable exception = assertThrows(Error.class, test::dequeue);
        assertEquals("Empty Queue", exception.getMessage());
    }

    @Test
    void shouldBeAbleToUseCircularBuffer() {
        QueueWithArray test = new QueueWithArray(3);
        test.enqueue(1);
        test.enqueue(2);
        test.dequeue();
        test.dequeue();
        test.enqueue(3);
        test.enqueue(4);
    }
}