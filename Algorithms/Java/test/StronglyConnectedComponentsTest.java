import org.junit.jupiter.api.Test;

import static junit.framework.TestCase.assertTrue;
import static junit.framework.TestCase.assertFalse;

class StronglyConnectedComponentsTest {
  @Test
  void addEdgeShouldNotError() {
    StronglyConnectedComponents test = new StronglyConnectedComponents(2);
    test.addEdge(0, 1);
  }

  @Test
  void isEdgeShouldReturnTrueIfEdgeExists() {
    StronglyConnectedComponents test = new StronglyConnectedComponents(2);
    test.addEdge(0, 1);
    assertTrue(test.isEdge(0, 1));
  }

  @Test
  void isEdgeShouldReturnFalseIfEdgeDoesNotExists() {
    StronglyConnectedComponents test = new StronglyConnectedComponents(2);
    assertFalse(test.isEdge(0, 1));
  }

  @Test
  void edgesShouldBeDirected() {
    StronglyConnectedComponents test = new StronglyConnectedComponents(2);
    test.addEdge(0, 1);
    assertTrue(test.isEdge(0, 1));
    assertFalse(test.isEdge(1, 0));
  }

  @Test
  void shouldTranspose() {
    StronglyConnectedComponents test = new StronglyConnectedComponents(2);
    test.addEdge(0, 1);
    assertTrue(test.isEdge(0, 1));
    StronglyConnectedComponents transpose = test.transpose();
    assertTrue(transpose.isEdge(1, 0));
  }

  @Test
  void shouldPrintSCGs() {
    StronglyConnectedComponents test = new StronglyConnectedComponents(5);
    test.addEdge(1, 0);
    test.addEdge(0, 2);
    test.addEdge(2, 1);
    test.addEdge(0, 3);
    test.addEdge(3, 4);
    System.out.println("Following are strongly connected components " +
        "in given graph ");
    test.findSCGs();
  }
}