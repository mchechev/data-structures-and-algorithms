package graphs;

public class DirectedGraph extends Graph {
    public DirectedGraph(int vertices) {
        super(vertices);
    }

    @Override
    public void addEdge(int from, int to) {
        adjacencyList.get(from).add(new ReachableVertex(to));
        edgesList.add(new Edge(from, to));
        edges++;
    }

    @Override
    public void addEdge(int from, int to, int cost) {
        adjacencyList.get(from).add(new ReachableVertex(to, cost));
        edgesList.add(new Edge(from, to, cost));
        edges++;
    }

    @Override
    public int[][] getAdjacencyMatrix() {
        int[][] matrix = new int[vertices][vertices];
        edgesList.forEach(edge -> {
            matrix[edge.from][edge.to] = edge.cost;
        });
        return matrix;
    }
}
