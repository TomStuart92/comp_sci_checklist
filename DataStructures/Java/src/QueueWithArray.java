public class QueueWithArray {
  private int[] queue;
  private int capacity;
  private int size;
  private int readIndex;
  private int writeIndex;

  QueueWithArray(int capacity) {
    this.queue = new int[capacity];
    this.capacity = capacity;
    this.size = 0;
    this.readIndex = 0;
    this.writeIndex = 0;
  }

  public int capacity() {
    return this.capacity;
  }

  public int size() {
    return this.size;
  }

  public boolean isEmpty() {
    return this.size == 0;
  }

  public boolean isFull() {
    return this.size == this.capacity;
  }

  public void enqueue(int key) {
    if(this.size == this.capacity - 1)
      throw new Error("Full Queue");
    this.queue[this.writeIndex] = key;
    incrementWriteIndex();
    this.size++;
  }

  public int dequeue() throws Error {
    if(this.size == 0)
      throw new Error("Empty Queue");
    this.size--;
    int item = this.queue[this.readIndex];
    this.incrementReadIndex();
    return item;
  }

  private void incrementReadIndex() {
    if (this.writeIndex < this.capacity - 1)
      this.writeIndex++;
    else
      this.writeIndex = 0;
  }

  private void incrementWriteIndex() {
    if (this.writeIndex < this.capacity - 1)
      this.writeIndex++;
    else
      this.writeIndex = 0;
  }
}