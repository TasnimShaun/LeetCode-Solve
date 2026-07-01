import java.util.*;

class Solution {
    public int maximumSafenessFactor(List<List<Integer>> grid) {

        int n = grid.size();

        int[][] mat = new int[n][n];

        // Convert List<List<Integer>> to int[][]
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                mat[row][col] = grid.get(row).get(col);
            }
        }

        if (mat[0][0] == 1 || mat[n - 1][n - 1] == 1)
            return 0;

        Queue<int[]> queue = new LinkedList<>();

        // Multi-source BFS
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (mat[row][col] == 1)
                    queue.offer(new int[]{row, col});
            }
        }

        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};

        while (!queue.isEmpty()) {

            int[] cur = queue.poll();

            int row = cur[0];
            int col = cur[1];

            int distance = mat[row][col];

            for (int i = 0; i < 4; i++) {

                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < n &&
                    mat[newRow][newCol] == 0) {

                    mat[newRow][newCol] = distance + 1;
                    queue.offer(new int[]{newRow, newCol});
                }
            }
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);

        pq.offer(new int[]{mat[0][0], 0, 0});
        mat[0][0] *= -1;

        while (!pq.isEmpty()) {

            int[] cur = pq.poll();

            int safe = cur[0];
            int row = cur[1];
            int col = cur[2];

            if (row == n - 1 && col == n - 1)
                return safe - 1;

            for (int i = 0; i < 4; i++) {

                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < n &&
                    mat[newRow][newCol] > 0) {

                    pq.offer(new int[]{
                        Math.min(safe, mat[newRow][newCol]),
                        newRow,
                        newCol
                    });

                    mat[newRow][newCol] *= -1;
                }
            }
        }

        return 0;
    }
}
