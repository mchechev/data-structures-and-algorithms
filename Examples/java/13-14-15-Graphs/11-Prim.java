package graphs;

import java.util.TreeSet;

public class Prim {
    /**
     * Find a minimum spanning three of a given graph using Prim's algorithm.
     * O(E log V)
     *
     * @param graph Given graph to find the minimum spanning tree of.
     * @return Graph object that is the required minimum spanning tree or null if the given graph is disjoint.
     */
    public static Graph minimumSpanningTree(Graph graph) {
        Graph minSpanningTree = new Graph(graph.vertices);

        Graph.ReachableVertex[] cost_to = new Graph.ReachableVertex[graph.vertices];
        for (int i = 0; i < cost_to.length; i++) {
            cost_to[i] = new Graph.ReachableVertex();
        }

        cost_to[0].cost = 0;

        boolean[] marked = new boolean[graph.vertices];

        TreeSet<Graph.ReachableVertex> heap = new TreeSet<>();
        heap.add(new Graph.ReachableVertex(0, 0));

        for (int iteration = 0; iteration < graph.vertices; iteration++) {
            if (heap.size() == 0) {
                return null;
            }

            int node = heap.pollFirst().to;
            marked[node] = true;

            if (cost_to[node].to != -1) {
                minSpanningTree.addEdge(node, cost_to[node].to, cost_to[node].cost);
            }

            graph.adjacencyList.get(node).forEach(neighbour -> {
                if (!marked[neighbour.to] && neighbour.cost < cost_to[neighbour.to].cost) {
                    heap.remove(new Graph.ReachableVertex(neighbour.to, cost_to[neighbour.to].cost));
                    cost_to[neighbour.to] = new Graph.ReachableVertex(node, neighbour.cost);
                    heap.add(new Graph.ReachableVertex(neighbour.to, cost_to[neighbour.to].cost));
                }
            });
        }

        return minSpanningTree;
    }
}
