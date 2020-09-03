package graphs;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Graph {
    public int vertices;
    public int edges;

    public boolean[] visited;

    public List<Edge> edgesList;
    public List<List<ReachableVertex>> adjacencyList;

    public Graph(int vertices) {
        this.vertices = vertices;
        this.visited = new boolean[vertices];

        this.edgesList = new ArrayList<>();

        this.adjacencyList = new ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            this.adjacencyList.add(new ArrayList<>());
        }
    }

    public void addEdge(int from, int to) {
        adjacencyList.get(from).add(new ReachableVertex(to));
        adjacencyList.get(to).add(new ReachableVertex(from));

        edgesList.add(new Edge(from, to));
        edgesList.add(new Edge(to, from));

        edges++;
    }

    public void addEdge(int from, int to, int cost) {
        adjacencyList.get(from).add(new ReachableVertex(to, cost));
        adjacencyList.get(to).add(new ReachableVertex(from, cost));

        edgesList.add(new Edge(from, to, cost));
        edgesList.add(new Edge(to, from, cost));

        edges++;
    }

    public int[][] getAdjacencyMatrix() {
        int[][] matrix = new int[vertices][vertices];
        edgesList.forEach(edge -> {
            matrix[edge.from][edge.to] = edge.cost;
            matrix[edge.to][edge.from] = edge.cost;
        });
        return matrix;
    }

    public static class Edge implements Comparable<Edge> {
        public int from;
        public int to;
        public int cost;

        public Edge(int from, int to) {
            this.from = from;
            this.to = to;
            this.cost = 0;
        }

        public Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge other) {
            if (this.cost == other.cost) {
                if (this.from == other.from) {
                    return Integer.compare(this.to, other.to);
                }
                return Integer.compare(this.from, other.from);
            }
            return Integer.compare(this.cost, other.cost);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Edge)) return false;
            Edge edge = (Edge) o;
            return this.compareTo(edge) == 0;
        }
    }

    public static class ReachableVertex implements Comparable<ReachableVertex> {
        public int to;
        public int cost;

        public ReachableVertex() {
            this.to = -1;
            this.cost = Integer.MAX_VALUE;
        }

        public ReachableVertex(int to) {
            this.to = to;
            this.cost = 0;
        }

        public ReachableVertex(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }

        @Override
        public int compareTo(ReachableVertex other) {
            if (this.cost == other.cost) {
                return Integer.compare(this.to, other.to);
            }
            return Integer.compare(this.cost, other.cost);
        }
    }
}
