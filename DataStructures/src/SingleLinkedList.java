// import SingleLinkedList.LinkNode;

public class SingleLinkedList {
    private LinkNode head;
    private LinkNode tail;
    private int size;

    SingleLinkedList(int data) {
        this.head = new LinkNode(data, null);
        this.tail = this.head;
        this.size = 1;
    }

    public int size() {
        return this.size;
    }

    public boolean isEmpty(){
        return this.size == 0;
    }

    public void pushFront(int value) {
       this.head = new LinkNode(value, this.head);
       this.size++;
    }

    public Integer popFront() {
        LinkNode front = this.head;
        this.head = front.next;
        return front.data;
    }

    public void pushBack(int value) {
        LinkNode newBack = new LinkNode(value, this.tail);
        this.tail.next = newBack;
        this.tail = newBack;
        this.size++;
    }

    public Integer popBack() {
        LinkNode back = this.tail;
        LinkNode current = this.head;
        LinkNode penultimate = null;

        while(current.hasNext()) {
            current = current.next;
            if(current.next == this.tail) {
                penultimate = current.next;
            }
        }
        penultimate.next = null;
        this.tail = penultimate;
        return back.data;
    }

    public Integer front() {
        return this.head.data; 
    }

    public Integer back() {
        return this.tail.data; 
    }

    private class LinkNode {
        private Integer data;
        private LinkNode next;

        LinkNode(Integer data, LinkNode next) {
            this.data = data;
            this.next = next;
        }

        public boolean hasNext(){
            return this.next != null;
        }
    }
}