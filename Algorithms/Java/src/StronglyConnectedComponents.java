import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Stack;

// implementation of Kosaraju algorithm

class StronglyConnectedComponents {
  private final int numberOfVertices;
  private final ArrayList<LinkedList<Integer>> adjacencyList;

  StronglyConnectedComponents(int numberOfVertices) {
    this.numberOfVertices = numberOfVertices;
    this.adjacencyList = new ArrayList<>(numberOfVertices);

    for(int i = 0; i < this.numberOfVertices; i++)
      this.adjacencyList.add(i, new LinkedList<>());
  }

  void addEdge(int v, int w) {
    this.adjacencyList.get(v).push(w);
  }

  boolean isEdge(int v, int w) {
    return this.adjacencyList.get(v).contains(w);
  }

  StronglyConnectedComponents transpose() {
    StronglyConnectedComponents transpose = new StronglyConnectedComponents(this.numberOfVertices);
    for(int v = 0; v < this.numberOfVertices; v++) {
      for (Integer integer : adjacencyList.get(v))
        transpose.addEdge(integer, v);
    }
    return transpose;
  }

  void findSCGs() {
    Stack<Integer> stack = new Stack<>();
    boolean visited[] = new boolean[this.numberOfVertices];
    for(int i = 0; i < this.numberOfVertices; i++)
        visited[i] = false;

    for(int i = 0; i< numberOfVertices; i++)
      if (!visited[i])
          fillOrder(i, visited, stack);

    StronglyConnectedComponents transpose = this.transpose();

    for(int i = 0; i < this.numberOfVertices; i++)
        visited[i] = false;

    while(!stack.empty()) {
      int v = stack.pop();
      if(!visited[v]) {
        transpose.DFSUtil(v, visited);
      }
    }
  }

  private void DFSUtil(int v, boolean visited[]) {
    visited[v] = true;
    System.out.println(v);
    int n;
    for (Integer integer : adjacencyList.get(v)) {
      n = integer;
      if (!visited[n]) {
        DFSUtil(n, visited);
        System.out.println();
      }
    }
  }

  private void fillOrder(int v, boolean visited[], Stack<Integer> stack) {
    visited[v] = true;

    for(Integer integer: adjacencyList.get(v)) {
      if(!visited[integer])
          fillOrder(integer, visited, stack);
    }
    stack.push(v);
  }
}