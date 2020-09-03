package graphs;

import java.util.Arrays;

public class NumberOfPathsOfFixedLength {
    public static class PathsIndex {
        private final int k;
        private int[][] matrix;

        /**
         * Create an index over the given graph that can answer
         * queries about the number of paths of some fixed length k.
         *
         * Build time: O(V^3)
         * Query time: O(1)
         *
         * @param k the length of the paths.
         */
        public PathsIndex(Graph g, int k) {
            this.k = k;
            matrix = g.getAdjacencyMatrix();
            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix.length; j++) {
                    if (matrix[i][j] > 0) {
                        matrix[i][j] = 1;
                    }
                }
            }
            matrix = powMatrix(matrix, k);
        }

        /**
         * Retrurns the number of paths starting at from and ending at to with length k.
         *
         * @param from starting vertex
         * @param to ending vertex
         * @return one integer - the number of paths.
         */
        public int paths(int from, int to) {
            return matrix[from][to];
        }

        /**
         * @return the length of the paths.
         */
        public int pathLength() {
            return k;
        }

        private int[][] powMatrix(int[][] mat, int degree) {
            if (degree == 0) {
                return identityMatrix(mat.length);
            }

            if (degree == 1) {
                return mat;
            }

            int[][] res = powMatrix(mat, degree / 2);

            res = multiplyMatrix(res, res);

            if (degree % 2 == 0) {
                return res;
            }

            return multiplyMatrix(res, mat);
        }

        private int[][] identityMatrix(int size) {
            int[][] res = new int[size][size];

            for (int i = 0; i < size; i++) {
                res[i][i] = 1;
            }

            return res;
        }

        private int[][] multiplyMatrix(int[][] a, int[][] b) {
            int[][] res = new int[a.length][a.length];

            for (int i = 0; i < a.length; i++) {
                for (int j = 0; j < a.length; j++) {
                    for (int p = 0; p < a.length; p++) {
                        res[i][j] += a[i][p] * b[p][j];
                    }
                }
            }

            return res;
        }
    }

    /**
     * Create an index over the given graph that can answer
     * queries about the number of paths of some fixed length k.
     *
     * Build time: O(V^3)
     * Query time: O(1)
     *
     * @param k the length of the paths.
     */
    public static PathsIndex createIndex(Graph graph, int k) {
        return new PathsIndex(graph, k);
    }
}
