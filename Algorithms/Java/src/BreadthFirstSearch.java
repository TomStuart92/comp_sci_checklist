import java.util.LinkedList;

class BreadthFirstSearch {
  private int V;
  private LinkedList<Integer> adj[];

  BreadthFirstSearch(int v) {
    V = v;
    adj = new LinkedList[v];
    for(int i=0; i<v; ++i)
      adj[i] = new LinkedList<>();
  }

  void addEdge(int v, int w) {
    adj[v].add(w);
  }

  public LinkedList<Integer> search(int s) {
    boolean visited[] = new boolean[V];
    LinkedList<Integer> queue = new LinkedList<>();
    LinkedList<Integer> nodes = new LinkedList<>();


    queue.push(s);

    while(queue.size() != 0) {
      s = queue.poll();
      nodes.push(s);
      for (Integer n : adj[s]) {
        if (!visited[n]) {
          visited[n] = true;
          queue.add(n);
        }
      }
    }
    return nodes;
  }
}