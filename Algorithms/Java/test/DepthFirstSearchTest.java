import org.junit.jupiter.api.Test;

class DepthFirstSearchTest {
    /*
    Edges
    1-2
    2-3
    3-4
    4-5
    5-3
    */

    @Test
    void shouldBeAbleToAddEdgesAndVertices() {
        DepthFirstSearch test = new DepthFirstSearch(5);
        test.addEdge(0,1);
        test.addEdge(1,2);
        test.addEdge(2,3);
        test.addEdge(3,4);
        test.addEdge(4,2);
    }

    @Test
    void shouldBeAbleToSearch() {
        DepthFirstSearch test = new DepthFirstSearch(5);
        test.addEdge(0,1);
        test.addEdge(1,2);
        test.addEdge(2,3);
        test.addEdge(3,4);
        test.addEdge(4,2);
        test.search(2);
    }

}