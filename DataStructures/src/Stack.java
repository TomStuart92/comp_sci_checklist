public class Stack {
    private int[] stack;
    private int capacity;
    private int size;

    Stack(int capacity) {
        this.stack = new int[capacity];
        this.capacity = capacity;
        this.size = 0;
    }

    public boolean isEmpty() {
        return this.size == 0;
    }

    public int size() {
        return this.size;
    }

    public int capacity() {
        return this.capacity;
    }

    public boolean isFull() {
        return this.size == this.capacity;
    }

    public void push(int item) throws Error {
        if(this.isFull())
            throw new Error("Stack Full");
        this.stack[this.size++] = item;
    }

    public int top() throws Error {
        if(this.isEmpty())
            throw new Error("Stack Empty");
        return this.stack[this.size - 1];
    }

    public int pop() throws Error {
        if(this.isEmpty())
            throw new Error("Stack Empty");
        return this.stack[--this.size];
    }
}


