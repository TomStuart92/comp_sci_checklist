public class BinarySearchTree {
  public Node head;
  private int nodeCount;

  BinarySearchTree() {
    this.head = null;
    this.nodeCount = 0;
  }

  public void insert(int key){
    Node newNode = new Node(key);
    if (head == null) {
      this.head = newNode;
      this.nodeCount++;
      return;
    }
    Node parent = this.findInsertLocation(key, this.head);
    newNode.parent = parent;
    if (newNode.key < parent.key) {
      parent.leftChild = newNode;
    } else {
      parent.rightChild = newNode;
    }
    this.nodeCount++;
  }

  public int getNodeCount() {
    return this.nodeCount;
  }

  public void printValues() {
    this.printSubtree(this.head);
  }

  public void deleteTree() {
    this.head = null;
    this.nodeCount = 0;
  }

  public boolean contains(int key) {
    Node targetNode = this.findInsertLocation(key, this.head);
    return targetNode.key == key;
  }

  public int getHeight() {
    // add one for the head node;
    return this.getLargestSubtreeHeight(this.head) + 1;
  }

  public int getMin() {
    Node current = this.head;
    while(current.leftChild != null) {
      current = current.leftChild;
    }
    return current.key;
  }

  public int getMax() {
    Node current = this.head;
    while(current.rightChild != null) {
      current = current.rightChild;
    }
    return current.key;
  }

  public int getSuccessor(int key) {
    Node target = this.findInsertLocation(key, this.head);
    if (target.rightChild != null)
      return target.rightChild.key;
    else if(target.parent.key > key)
      return target.parent.key;
    return -1;
  }

  public static boolean isBinaryTree(Node head) {
    if (head == null)
      return true;
    Boolean leftCheck = true;
    Boolean rightCheck = true;

    if (head.leftChild != null && (head.key < head.leftChild.key))
      leftCheck = false;
    if (head.rightChild != null && (head.key > head.rightChild.key))
      rightCheck = false;
    return leftCheck && rightCheck && isBinaryTree(head.leftChild) && isBinaryTree(head.rightChild);
  }

  public void deleteValue(int key) {
    Node target = this.findInsertLocation(key, this.head);
    Node parent = target.parent;
    if(target.leftChild == null && target.rightChild == null) {
      //leaf node
      if(target.parent.leftChild == target) {
        target.parent.leftChild = null;
      } else {
        target.parent.rightChild = null;
      }
    } else if (target.leftChild != null && target.rightChild == null) {
      // single left child
      parent.leftChild = target.leftChild;
    } else if (target.leftChild == null && target.rightChild != null) {
      // single right child
      parent.rightChild = target.rightChild;
    } else {
      Node nextLargest = target.rightChild;
      while(nextLargest.leftChild != null) {
        nextLargest = nextLargest.leftChild;
      }
      this.swap(target, nextLargest);
      if(target.parent.leftChild == target) {
        target.parent.leftChild = null;
      } else {
        target.parent.rightChild = null;
      }
    }
  }

  private void swap(Node a, Node b) {
    Node temp = new Node(a.key);
    a.key = b.key;
    a.parent = b.parent;
    a.rightChild = b.rightChild;
    a.leftChild = b.leftChild;
    b.key = temp.key;
    b.leftChild = temp.leftChild;
    b.rightChild = temp.rightChild;
    b.parent = temp.parent;
  }

  private void printSubtree(Node current) {
    if (current.leftChild != null)
      printSubtree(current.leftChild);
    System.out.print(current.key + ", ");
    if (current.rightChild != null)
      printSubtree(current.rightChild);
  }

  private Node findInsertLocation(int key, Node current) {
    if(key < current.key) {
      if(current.leftChild == null) return current;
      return findInsertLocation(key, current.leftChild);
    } else {
      if(current.rightChild == null) return current;
      return findInsertLocation(key, current.rightChild);
    }
  }

  private int getLargestSubtreeHeight(Node current) {
    if(current.leftChild == null && current.rightChild == null)
      return 1;
    else if(current.leftChild != null && current.rightChild != null) {
      int leftSize = this.getLargestSubtreeHeight(current.leftChild);
      int rightSize = this.getLargestSubtreeHeight(current.rightChild);
      return leftSize > rightSize ? leftSize : rightSize;
    }
    else if(current.leftChild != null)
      return this.getLargestSubtreeHeight(current.leftChild);
    else
      return this.getLargestSubtreeHeight(current.rightChild);
  }


  private class Node {
    int key;
    Node parent;
    Node leftChild;
    Node rightChild;

    Node(int key) {
      this.key = key; 
    }
  }
}

