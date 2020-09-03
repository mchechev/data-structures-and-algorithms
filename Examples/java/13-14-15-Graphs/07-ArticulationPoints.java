package graphs;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Find all articulation points in a graph
 * O(V + E) complexity
 */
public class ArticulationPoints {
    /**
     * Returns a list of all the articulation points in the given graph
     */
    public static List<Integer> getArticulationPoints(Graph graph) {
        List<Integer> result = new ArrayList<>();
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

    private static void dfs(Graph graph, int node, int parent, int[] in, int[] low, Integer timer, List<Integer> articulationPoints) {
        graph.visited[node] = true;
        in[node] = low[node] = timer++;

        int splits = 0;
        for (Graph.ReachableVertex neighbour : graph.adjacencyList.get(node)) {
            if (!graph.visited[neighbour.to]) {
                dfs(graph, neighbour.to, node, in, low, timer, articulationPoints);

                low[node] = Math.min(low[node], low[neighbour.to]);

                if (low[neighbour.to] >= in[node] && parent != -1) {
                    articulationPoints.add(node);
                }

                splits++;
            } else if (neighbour.to != parent) {
                low[node] = Math.min(low[node], in[neighbour.to]);
            }
        }

        if (parent == -1 && splits > 1) {
            articulationPoints.add(node);
        }
    }
}

