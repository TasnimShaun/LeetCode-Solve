class Solution {
    public boolean findSafeWalk(List<List<Integer>> grid, int health) {

        int rows = grid.size();
        int cols = grid.get(0).size();

        int[][] cost = new int[rows][cols];

        for (int row = 0; row < rows; row++) {
            java.util.Arrays.fill(cost[row], Integer.MAX_VALUE);
        }

        ArrayDeque<int[]> dq = new ArrayDeque<>();

        cost[0][0] = grid.get(0).get(0);
        dq.offerFirst(new int[]{0, 0});

        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};

        while (!dq.isEmpty()) {

            int[] cur = dq.pollFirst();

            int row = cur[0];
            int col = cur[1];

            for (int i = 0; i < 4; i++) {

                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow < 0 || newRow >= rows ||
                    newCol < 0 || newCol >= cols)
                    continue;

                int newHealthLoss = cost[row][col] + grid.get(newRow).get(newCol);

                if (newHealthLoss < cost[newRow][newCol]) {

                    cost[newRow][newCol] = newHealthLoss;

                    if (grid.get(newRow).get(newCol) == 0)
                        dq.offerFirst(new int[]{newRow, newCol});
                    else
                        dq.offerLast(new int[]{newRow, newCol});
                }
            }
        }

        return cost[rows - 1][cols - 1] < health;
    }
}
