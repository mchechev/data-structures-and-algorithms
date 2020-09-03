package graphs;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

/**
 * Implementation of topological sorting
 * Works for acyclic directed graph (DAG)
 * O(n) complexity
 */
public class TopologicalSort {
    /**
     * Returns a list of all the vertices of the graph in their sorted order.
     */
    public static List<Integer> sortedVertices(DirectedGraph graph) {
        List<Integer> result = new ArrayList<>();
        Stack<Integer> s = new Stack<>();
        Arrays.fill(graph.visited, false);

        for (int vertex = 0; vertex < graph.vertices; vertex++) {
            if (!graph.visited[vertex]) {
                topSort(graph, vertex, s);
            }
        }
        Arrays.fill(graph.visited, false);

        while (!s.empty()) {
            result.add(s.pop());
        }
        return result;
    }

    private static void topSort(DirectedGraph graph, int vertex, Stack<Integer> s) {
        graph.visited[vertex] = true;

        graph.adjacencyList.get(vertex).forEach(neighbour -> {
            if (!graph.visited[neighbour.to]) {
                topSort(graph, neighbour.to, s);
            }
        });

        s.push(vertex);
    }
}
