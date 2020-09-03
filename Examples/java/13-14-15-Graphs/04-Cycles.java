package graphs;

import java.util.Arrays;

public class Cycles {
    /**
     * Check if a graph contains a cycle.
     * O(V + E)
     *
     * @param graph Graph or DirectedGraph object.
     * @return true if the given graph has a cycle and false otherwise.
     */
    public static boolean findCycle(Graph graph) {
        int[] colour = new int[graph.vertices];
        Arrays.fill(colour, 0);

        if (graph instanceof DirectedGraph) {
            return findCycleDfs((DirectedGraph) graph, 0, colour);
        }

        return findCycleDfs(graph, 0, -1, colour);
    }

    private static boolean findCycleDfs(Graph graph, int vertex, int parent, int[] colour) {
        colour[vertex] = 1;

        for (Graph.ReachableVertex neighbour : graph.adjacencyList.get(vertex)) {
            if (colour[neighbour.to] == 0) {
                if (findCycleDfs(graph, neighbour.to, vertex, colour)) {
                    return true;
                }
            } else if (colour[neighbour.to] == 1 && vertex != parent) {
                return true;
            }
        }

        colour[vertex] = 2;
        return false;
    }

    private static boolean findCycleDfs(DirectedGraph graph, int vertex, int[] colour) {
        colour[vertex] = 1;

        for (Graph.ReachableVertex neighbour : graph.adjacencyList.get(vertex)) {
            if (colour[neighbour.to] == 0) {
                if (findCycleDfs(graph, neighbour.to, vertex, colour)) {
                    return true;
                }
            } else if (colour[neighbour.to] == 1) {
                return true;
            }
        }

        colour[vertex] = 2;
        return false;
    }
}
