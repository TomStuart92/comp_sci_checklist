import java.util.*;

public class DepthFirstSearch {
    private int numberOfVertices;
    private LinkedList<Integer> adjacencyMatrix[];

    DepthFirstSearch(int v) {
        this.numberOfVertices = v;
        adjacencyMatrix = new LinkedList[v];
        for(int i=0; i < adjacencyMatrix.length; i++)
            adjacencyMatrix[i] = new LinkedList<>();
    }

    void addEdge(int v, int w) {
        adjacencyMatrix[v].add(w);
    }

    public void search(int s) {
        Vector<Boolean> visited = new Vector<>(this.numberOfVertices);

        for(int i = 0; i < this.numberOfVertices; i++) {
            visited.add(false);
        }

        Stack<Integer> stack = new Stack<>();
        stack.push(s);

        while (!stack.empty()) {
            s = stack.peek();
            stack.pop();

            if(!visited.get(s))
                visited.set(s, true);

            for (Integer v : this.adjacencyMatrix[s]) {
                if (!visited.get(v))
                    stack.push(v);
            }
        }
    }
}
