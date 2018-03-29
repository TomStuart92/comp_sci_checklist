import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Stack;

class TopologicalSort {
  private final int numberOfVertices;
  private final ArrayList<LinkedList<Integer>> adjacencyList;

  TopologicalSort(int numberOfVertices) {
    this.numberOfVertices = numberOfVertices;
    adjacencyList = new ArrayList<>(numberOfVertices);
    for(int i = 0; i < numberOfVertices; i++)
      adjacencyList.add(i, new LinkedList<>());
  }

  void addEdge(int v, int w) {
    LinkedList<Integer> vertex = adjacencyList.get(v);
    vertex.push(w);
  }

  private void topologicalSortUtility(int v, boolean visited[], Stack<Integer> stack) {
    visited[v] = true;
    Integer i;

    for (Integer integer : adjacencyList.get(v)) {
      i = integer;
      if (!visited[i])
        topologicalSortUtility(i, visited, stack);
    }
    stack.push(v);
  }

  Stack<Integer> topologicalSort() {
    Stack<Integer> stack = new Stack<>();
    boolean visited[] = new boolean[this.numberOfVertices];
    for (int i = 0; i < this.numberOfVertices; i++)
      visited[i] = false;

    for(int i = 0; i < this.numberOfVertices; i++)
        if (!visited[i])
            topologicalSortUtility(i, visited, stack);
    return stack;
  }
}