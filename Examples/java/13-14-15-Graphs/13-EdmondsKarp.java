package graphs;

import basic.data.structures.Queue;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Find the maximum flow in a graph
 * The cost property will be the edge capacity
 * O(VE^2) complexity
 */
public class EdmondsKarp {
    /**
     * Return the maximum flow in the given graph from the source to the sink
     */
    public static int maxFlow(Graph graph, int source, int sink) {
        int flow = 0;
        int[][] capacity = graph.getAdjacencyMatrix();
        int[] parent = new int[graph.vertices];

        int currentFLow = bfs(graph, source, sink, parent, capacity);
        while (currentFLow != 0) {
            flow += currentFLow;

            int node = sink;
            while (node != source) {
                int previous = parent[node];
                capacity[previous][node] -= currentFLow;
                capacity[node][previous] += currentFLow;
                node = previous;
            }

            currentFLow = bfs(graph, source, sink, parent, capacity);
        }

        return flow;
    }

    private static int bfs(Graph g, int from, int to, int[] parent, int[][] capacity) {
        Arrays.fill(parent, -1);
        parent[from] = Integer.MIN_VALUE;

        Queue<Pair<Integer, Integer>> q = new Queue<>();
        q.push(new Pair<>(from, Integer.MAX_VALUE));

        while (!q.empty()) {
            int node = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (Graph.ReachableVertex neighbour : g.adjacencyList.get(node)) {
                if (parent[neighbour.to] == -1 && capacity[node][neighbour.to] != 0) {
                    parent[neighbour.to] = node;
                    int current_flow = Math.min(flow, capacity[node][neighbour.to]);

                    if (neighbour.to == to) {
                        return current_flow;
                    }

                    q.push(new Pair<>(neighbour.to, current_flow));
                }
            }
        }

        return 0;
    }

    private static class Pair<F, S> {
        public F first;
        public S second;

        public Pair(F f, S s) {
            first = f;
            second = s;
        }
    }
}
