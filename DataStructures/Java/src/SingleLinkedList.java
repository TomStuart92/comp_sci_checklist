// import SingleLinkedList.LinkNode;

public class SingleLinkedList {
    private LinkNode head;
    private LinkNode tail;
    private int size;

    SingleLinkedList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public int size() {
        return this.size;
    }

    public boolean isEmpty(){
        return this.size == 0;
    }

    public void pushFront(int value) {
       this.insertAt(0, value);
    }

    public Integer popFront() {
        return this.erase(0);
    }

    public void pushBack(int value) {
        this.insertAt(this.size, value);
    }

    public Integer popBack() {
        return this.erase(this.size - 1);
    }

    public int front() throws Error {
        if (this.head == null)
            throw new Error("No Head Node");
        return this.head.data; 
    }

    public int back() throws Error {
        if (this.tail == null)
            throw new Error("No Tail Node");
        return this.tail.data; 
    }

    public void insertAt(int index, int data) {
        if (0 > index || this.size < index)
            throw new ArrayIndexOutOfBoundsException("No Node At Index: " + index);

        LinkNode newNode = new LinkNode(data, null);

        if(this.size == 0) {
            this.head = newNode;
            this.tail = this.head;
            this.size++;
            return;
        }

        if(index == 0) {
            newNode.next = this.head;
            this.head = newNode;
            this.size++;
            return;
        }

        LinkNode previousNode = nodeAt(index - 1);

        if(index == this.size) {
            previousNode.next = newNode;
            this.tail = newNode;
            this.size++;
            return;
        }


        newNode.next = previousNode.next;
        previousNode.next = newNode;
        this.size++;
    }

    public Integer erase(int index) {
        if (0 > index || this.size < index || this.size == 0)
            throw new ArrayIndexOutOfBoundsException("No Node At Index: " + index);

        if(index == 0) {
            LinkNode currentHead = this.head;
            this.head = currentHead.next;
            this.size--;
            return currentHead.data;
        }

        LinkNode previousNode = nodeAt(index - 1);

        if(index == this.size - 1) {
            previousNode.next = null;
            LinkNode lastNode = this.tail;
            this.tail = previousNode;
            this.size--;
            return lastNode.data;
        }

        LinkNode deletedNode = previousNode.next;
        previousNode.next = deletedNode.next;
        this.size--;
        return deletedNode.data;
    }

    public Integer valueAt(int index) {
        return this.nodeAt(index).data;
    }

    public Integer valueNFromEnd(int n) {
        int index = this.size - n - 1;
        return this.nodeAt(index).data;
    }

    public void reverse() {
        LinkNode slow = this.head;
        LinkNode fast = slow.next;

        while (slow != fast) {
            if (fast.hasNext()) {
                LinkNode nextNode = fast.next;
                fast.next = slow;
                slow = fast;
                fast = nextNode;
            } else {
                fast.next = slow;
                slow = fast;
            }
        }
        this.tail = this.head;
        this.tail.next = null;
        this.head = slow;
    }

    public void removeValue(int value) throws Error {
        LinkNode current = this.head;
        for(int i = 0; i < this.size - 1; i++) {
            current = current.next;
            if(current.data == value) {
                this.erase(i + 1);
                return;
            }
        }
        throw new Error("Value Not Found");
    }

    private LinkNode nodeAt(int index) {
        LinkNode current = this.head;
        for(int i = 0; i < index; i++) {
            current = current.next;
        }
        return current;

    }

    private class LinkNode {
        private Integer data;
        private LinkNode next;

        LinkNode(Integer data, LinkNode next) {
            this.data = data;
            this.next = next;
        }

        boolean hasNext(){
            return this.next != null;
        }
    }
}