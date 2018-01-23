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

    public int at(int index) throws ArrayIndexOutOfBoundsException {
        this.indexCheck(index);
        return this.items[index];
    }

    public void push(int item) {
        if (this.isFull()) 
            this.resize(this.capacity * this.resizeFactor);
        this.items[this.itemCount++] = item;
    }

    public void insert(int index, int item) throws ArrayIndexOutOfBoundsException{
        this.indexCheck(index);
        if (this.isFull()) 
            this.resize(this.capacity * this.resizeFactor);
        System.arraycopy(this.items, index, this.items, index + 1, this.itemCount - index);
        this.items[index] = item;
        this.itemCount += 1;
    }

    public void prepend(int item) {
        this.insert(0, item);
    }

    public int pop() {
        int value = this.items[this.itemCount -1];
        this.delete(0);
        return value;
    }

    public void delete(int index) throws ArrayIndexOutOfBoundsException {
        this.indexCheck(index);
        System.arraycopy(this.items, index + 1, this.items, index, this.itemCount - 1 - index);
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

    private void indexCheck(int index) throws ArrayIndexOutOfBoundsException {
        if(!isValidIndex(index))
            throw new ArrayIndexOutOfBoundsException();
    } 
    private boolean isValidIndex(int index) {
        return index >= 0 && index <= this.capacity;
    }

    private boolean isFull() {
        return this.capacity == this.itemCount;
    }

    private void resize(int newCapacity) {
        assert newCapacity > this.capacity;
        int[] temp = new int[newCapacity];
        System.arraycopy(this.items, 0, temp, 0, this.capacity);
        this.items = temp;
        this.capacity = newCapacity;
    }
}
