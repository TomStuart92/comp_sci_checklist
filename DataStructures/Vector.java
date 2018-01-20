class Vector {
    private int[] items;
    private int resizeFactor;
    private int capacity;
    private int itemCount;

    Vector(){
        this.itemCount = 0;
        this.capacity = 2;
        this.resizeFactor = 2;
        this.items = new int[this.capacity];
    }

    public int size() {
        return this.itemCount;
    }

    public int capacity() {
        return this.capacity;
    }

    public boolean isEmpty() {
        return this.itemCount == 0;
    }

    public int at(int index) {
        if(!isValidIndex(index))
            throw new ArrayIndexOutOfBoundsException();
        return this.items[index];
    }

    public void push(int item) {
        if (this.isFull()) 
            this.resize(this.capacity * this.resizeFactor);
        this.items[this.itemCount++] = item;
    }

    public void insert(int index, int item) {
        if (this.isFull()) 
            this.resize(this.capacity * this.resizeFactor);
        for(int i = this.itemCount + 1; i >= index; i--) {
            this.items[i] = this.items[i-1];
        }
        this.items[index] = item;
        this.itemCount += 1;
    }

    public void prepend(int item) {
        this.insert(0, item);
    }

    public int pop() {
        return this.items[this.itemCount--];
    }

    public void delete(int index) {
        for(int i = index; i < this.itemCount; i++) {
            this.items[i] = this.items[i + 1];
        }
        this.itemCount -= 1;
    }

    public int find(int item) {
        for(int i = 0; i < this.itemCount; i++) {
            if(this.items[i] == item)
                return i;
        }
        return -1;
    }

    public void remove(int item) {
        int index = this.find(item);
        this.delete(index);
    }

    private boolean isValidIndex(int index) {
        return index > 0 && index <= this.capacity;
    }

    private boolean isFull() {
        return this.capacity == this.itemCount;
    }

    private void resize(int newCapacity) {
        assert newCapacity > this.capacity;
        int[] temp = new int[newCapacity];
        for (int i = 0; i < this.capacity; i++) {
            temp[i] = this.items[i];
        }
        this.items = temp;
        this.capacity = newCapacity;
    }
}
