public class QueueWithLinkedList {
    private SingleLinkedList queue;

    QueueWithLinkedList() {
        this.queue = new SingleLinkedList();
    }

    public int size() {
        return this.queue.size();
    }

    public boolean isEmpty() {
        return this.queue.isEmpty();
    }

    public void enqueue(int key) {
        this.queue.pushBack(key);
    }

    public int dequeue() throws Error {
        return this.queue.popFront();
    }
}