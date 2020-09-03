package graphs;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Find all bridges in a graph
 * O(V + E) complexity
 */
public class Bridges {
    /**
     * Returns a list of all the brides in the given graph
     */
    public static List<Graph.Edge> getBridges(Graph graph) {
        List<Graph.Edge> result = new ArrayList<>();
        int[] in = new int[graph.vertices];
        int[] low = new int[graph.vertices];
        Integer timer = 0;
        Arrays.fill(graph.visited, false);

        for (int vertex = 0; vertex < graph.vertices; vertex++) {
            if (!graph.visited[vertex]) {
                dfs(graph, vertex, -1, in, low, timer, result);
            }
        }
        Arrays.fill(graph.visited, false);

        return result;
    }

    private static void dfs(Graph graph, int node, int parent, int[] in, int[] low, Integer timer, List<Graph.Edge> bridges) {
        graph.visited[node] = true;
        in[node] = low[node] = timer++;

        for (Graph.ReachableVertex neighbour : graph.adjacencyList.get(node)) {
            if (!graph.visited[neighbour.to]) {
                dfs(graph, neighbour.to, node, in, low, timer, bridges);

                low[node] = Math.min(low[node], low[neighbour.to]);

                if (low[neighbour.to] > in[node]) {
                    bridges.add(new Graph.Edge(node, neighbour.to));
                }
            } else if (neighbour.to != parent) {
                low[node] = Math.min(low[node], in[neighbour.to]);
            }
        }
    }
}
