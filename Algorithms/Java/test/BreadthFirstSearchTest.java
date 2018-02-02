import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.LinkedList;

import static org.junit.jupiter.api.Assertions.*;

class BreadthFirstSearchTest {

    /*
    Edges
    1-2
    2-3
    3-4
    4-5
    5-3
    */

    @Test
    void shouldBeAbleToAddEdges() {
        BreadthFirstSearch test = new BreadthFirstSearch(5);
        test.addEdge(0,1);
        test.addEdge(1,2);
        test.addEdge(2,3);
        test.addEdge(3,4);
        test.addEdge(4,2);
    }

    @Test
    void shouldBeAbleToASearchBreadthFirst() {
        BreadthFirstSearch test = new BreadthFirstSearch(5);
        test.addEdge(0,1);
        test.addEdge(1,2);
        test.addEdge(2,3);
        test.addEdge(3,4);
        test.addEdge(4,2);
        LinkedList<Integer> result = test.search(2);
        LinkedList<Integer> expected = new LinkedList(Arrays.asList(4, 3, 2));
        assertEquals(expected, result);
    }
}