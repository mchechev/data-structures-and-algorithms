package graphs;

import java.util.Arrays;
import java.util.TreeSet;

public class Dijkstra {
    /**
     * Find the distance from a starting vertex to all other using the Dijkstra algorithm.
     * O(E log V) complexity.
     *
     * @param graph Graph to be processed.
     * @param start starting vertex.
     * @return int array filled with the distance to all vertices.
     */
    public static int[] dijkstraSparse(Graph graph, int start) {
        int[] dist = new int[graph.vertices];
        Arrays.fill(dist, Integer.MAX_VALUE);

        TreeSet<Graph.ReachableVertex> heap = new TreeSet<>();
        heap.add(new Graph.ReachableVertex(start, 0));
        dist[start] = 0;

        while (!heap.isEmpty()) {
            int vertex = heap.pollFirst().to;

            graph.adjacencyList.get(vertex).forEach(neighbour -> {
                if (dist[vertex] + neighbour.cost < dist[neighbour.to]) {
                    heap.remove(new Graph.ReachableVertex(neighbour.to, dist[neighbour.to]));
                    dist[neighbour.to] = dist[vertex] + neighbour.cost;
                    heap.add(new Graph.ReachableVertex(neighbour.to, dist[neighbour.to]));
                }
            });
        }

        return dist;
    }

    /**
     * Find the distance from a starting vertex to all other using the Dijkstra algorithm.
     * O(V^2) complexity.
     *
     * @param graph Graph to be processed.
     * @param start starting vertex.
     * @return int array filled with the distance to all vertices.
     */
    public static int[] dijkstraDense(Graph graph, int start) {
        int[] dist = new int[graph.vertices];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;

        boolean[] marked = new boolean[graph.vertices];

        for (int iteration = 1; iteration < graph.vertices; iteration++) {
            int vertex = -1;

            for (int i = 0; i < graph.vertices; i++) {
                if (marked[i]) {
                    continue;
                }

                if (vertex == -1 || dist[vertex] > dist[i]) {
                    vertex = i;
                }
            }

            marked[vertex] = true;

            for (Graph.ReachableVertex neighbour : graph.adjacencyList.get(vertex)) {
                if (dist[vertex] + neighbour.cost < dist[neighbour.to]) {
                    dist[neighbour.to] = dist[vertex] + neighbour.cost;
                }
            }
        }

        return dist;
    }
}
