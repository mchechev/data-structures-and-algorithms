package graphs;

import java.util.Arrays;

public class BellmanFord {
    /**
     * Find the distance from a starting vertex to all other using the Bellman-Ford algorithm.
     * O(VE) complexity.
     *
     * @param graph Graph to be processed.
     * @param start starting vertex.
     * @return int array filled with the distance to all vertices.
     */
    public static int[] shortestPaths(Graph graph, int start) {
        int[] dist = new int[graph.vertices];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;

        boolean relaxed = true;

        while (relaxed) {
            relaxed = false;

            for (Graph.Edge edge : graph.edgesList) {
                if (dist[edge.from] == Integer.MAX_VALUE) {
                    continue;
                }

                if (dist[edge.from] + edge.cost < dist[edge.to]) {
                    dist[edge.to] = dist[edge.from] + edge.cost;
                    relaxed = true;
                }
            }
        }

        return dist;
    }
}
