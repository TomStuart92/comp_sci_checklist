import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class BinarySearchTreeTest {
  @Test
  void shouldBeAbleToInsertAKey() {
    BinarySearchTree test = new BinarySearchTree();
    test.insert(1);
  }

  @Test
  void shouldBeAbleToInsertMultipleKeys() {
    BinarySearchTree test = new BinarySearchTree();
    test.insert(3);
    test.insert(1);
    test.insert(4);
  }

  @Test
  void shouldBeAbleToGetNodeCount() {
    BinarySearchTree test = new BinarySearchTree();
    test.insert(3);
    test.insert(2);
    test.insert(4);
    assertEquals(3, test.getNodeCount());
  }

  @Test
  void shouldBeAbleToPrintTree() {
    BinarySearchTree test = new BinarySearchTree();
    test.insert(3);
    test.insert(1);
    test.insert(4);
    test.insert(2);
    test.insert(5);
    test.printValues();
  }

  @Test
  void shouldBeAbleToDeleteTree() {
    BinarySearchTree test = new BinarySearchTree();
    test.insert(3);
    test.insert(2);
    test.insert(4);
    test.deleteTree();
    assertEquals(0, test.getNodeCount());
  }

  @Test
  void shouldBeAbleToTestIfValueInTree() {
    BinarySearchTree test = new BinarySearchTree();
    test.insert(3);
    test.insert(2);
    test.insert(4);
    assertEquals(true, test.contains(2));
    assertEquals(false, test.contains(1));
  }

  @Test
  void shouldBeAbleToGetHeight() {
    BinarySearchTree test = new BinarySearchTree();
    test.insert(3);
    test.insert(2);
    test.insert(4);
    assertEquals(2, test.getHeight());
  }

  @Test
  void shouldBeAbleToGetMinimumValue() {
    BinarySearchTree test = new BinarySearchTree();
    test.insert(3);
    test.insert(2);
    test.insert(4);
    assertEquals(2, test.getMin());
  }

  @Test
  void shouldBeAbleToGetMaximumValue() {
    BinarySearchTree test = new BinarySearchTree();
    test.insert(3);
    test.insert(2);
    test.insert(4);
    assertEquals(4, test.getMax());
  }

  @Test
  void shouldBeAbleToTestBST() {
    BinarySearchTree test = new BinarySearchTree();
    test.insert(3);
    test.insert(2);
    test.insert(4);
    assertEquals(true, BinarySearchTree.isBinaryTree(test.head));
  }

  @Test
  void shouldBeAbleToGetSuccessor() {
    BinarySearchTree test = new BinarySearchTree();
    test.insert(3);
    test.insert(2);
    test.insert(4);
    assertEquals(3, test.getSuccessor(2));
  }

  @Test
  void shouldBeAbleToDeleteAnItem() {
    BinarySearchTree test = new BinarySearchTree();
    test.insert(3);
    test.insert(2);
    test.deleteValue(2);
    assertEquals(false, test.contains(2));
  }
}