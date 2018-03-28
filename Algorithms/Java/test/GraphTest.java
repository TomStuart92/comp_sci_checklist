import org.junit.jupiter.api.Test;

import java.util.Stack;

class GraphTest {
  @Test
  void shouldAddEdge() {
    Graph test = new Graph(2);
    test.addEdge(0, 1);
  }

  @Test
  void shouldTopologicalSort() {
    Graph test = new Graph(6);
    test.addEdge(5, 2);
    test.addEdge(5, 0);
    test.addEdge(4, 0);
    test.addEdge(4, 1);
    test.addEdge(2, 3);
    test.addEdge(3, 1);

    Stack<Integer> topologicalSort = test.topologicalSort();
    while (!topologicalSort.empty())
      System.out.print(topologicalSort.pop() + " ");
  }
}