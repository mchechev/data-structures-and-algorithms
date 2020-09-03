package graphs;

import java.util.Iterator;

public class Kruskal {
    /**
     * Find a minimum spanning three of a given graph using Kruskal's algorithm.
     * O(E log V)
     *
     * @param graph Given graph to find the minimum spanning tree of.
     * @return Graph object that is the required minimum spanning tree or null if the given graph is disjoint.
     */
    public static Graph minimumSpanningTree(Graph graph) {
        Graph minSpanningTree = new Graph(graph.vertices);
        graph.edgesList.sort(Graph.Edge::compareTo);

        DisjointSet disjointSet = new DisjointSet(graph.vertices);

        int components = graph.vertices;
        Iterator<Graph.Edge> it = graph.edgesList.iterator();

        while (components > 1) {
            if (!it.hasNext()) {
                return null;
            }

            Graph.Edge edge = it.next();

            int root1 = disjointSet.find(edge.from);
            int root2 = disjointSet.find(edge.to);

            if (root1 != root2) {
                disjointSet.unite(root1, root2);
                minSpanningTree.addEdge(edge.from, edge.to, edge.cost);
                components--;
            }
        }

        return minSpanningTree;
    }

    private static class DisjointSet {
        private static class Set {
            int parent;
            int depth;

            public Set(int parent) {
                this.depth = 0;
                this.parent = parent;
            }
        }

        private final Set[] set;

        public DisjointSet(int size) {
            this.set = new Set[size];
            for (int i = 0; i < size; i++) {
                this.set[i] = new Set(i);
            }
        }

        public int find(int a) {
            if (a == set[a].parent) {
                return a;
            }

            int root = find(set[a].parent);
            set[a].parent = root;

            return root;
        }

        public void unite(int a, int b) {
            if (set[a].depth > set[b].depth) {
                set[b].parent = a;
            } else if (set[b].depth > set[a].depth) {
                set[a].parent = b;
            } else {
                set[b].parent = a;
                set[a].depth++;
            }
        }
    }
}
