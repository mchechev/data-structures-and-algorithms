package graphs;

public class Floyd {
    /**
     * Find the distance between every pair of vertices from the given graph.
     * O(V^3) complexity.
     *
     * @param graph Graph to be processed.
     * @return int matrix containing the distances between each pair of vertices.
     */
    public static int[][] floyd(Graph graph) {
        int[][] adjacencyMatrix = graph.getAdjacencyMatrix();
        int[][] dist = new int[graph.vertices][graph.vertices];

        for (int u = 0; u < graph.vertices; u++) {
            for (int v = 0; v < graph.vertices; v++) {
                if (adjacencyMatrix[u][v] == 0 && u != v) {
                    dist[u][v] = Integer.MAX_VALUE;
                } else {
                    dist[u][v] = adjacencyMatrix[u][v];
                }
            }
        }

        for (int k = 0; k < graph.vertices; k++) {
            for (int u = 0; u < graph.vertices; u++) {
                for (int v = 0; v < graph.vertices; v++) {
                    if (dist[u][k] != Integer.MAX_VALUE && dist[k][v] != Integer.MAX_VALUE) {
                        dist[u][v] = Math.min(dist[u][v], dist[u][k] + dist[k][v]);
                    }
                }
            }
        }

        return dist;
    }
}
