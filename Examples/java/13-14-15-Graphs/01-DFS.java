package graphs;

import java.util.Stack;

public class DFS {
    public static void dfs(Graph graph, int vertex) {
        graph.visited[vertex] = true;

        graph.adjacencyList.get(vertex).forEach(neighbour -> {
            if (!graph.visited[neighbour.to]) {
                dfs(graph, neighbour.to);
            }
        });
    }
    
    public static void dfsIterative(Graph graph, int start) {
        Stack<Integer> stack = new Stack<>();
        stack.push(start);
        graph.visited[start] = true;
        
        while (!stack.empty()) {
            int vertex = stack.pop();

            graph.adjacencyList.get(vertex).forEach(neighbour -> {
                if (!graph.visited[neighbour.to]) {
                    stack.push(neighbour.to);
                    graph.visited[neighbour.to] = true;
                }
            });
        }
    }
}
