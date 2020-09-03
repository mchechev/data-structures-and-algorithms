package graphs;

import basic.data.structures.Queue;

public class BFS {
    public static void bfs(Graph graph, int start) {
        Queue<Integer> queue = new Queue<>();
        queue.push(start);
        graph.visited[start] = true;

        while (!queue.empty()) {
            int vertex = queue.poll();

            graph.adjacencyList.get(vertex).forEach(neighbour -> {
                if (!graph.visited[neighbour.to]) {
                    queue.push(neighbour.to);
                    graph.visited[neighbour.to] = true;
                }
            });
        }
    }
}
