class Solution {

    public int[] pathsWithMaxScore(List<String> board) {

        final int MOD = 1000000007;

        int n = board.size();

        int[] nextScore = new int[n + 1];
        int[] nextWays = new int[n + 1];

        Arrays.fill(nextScore, -1);

        for (int row = n - 1; row >= 0; row--) {

            int[] currentScore = new int[n + 1];
            int[] currentWays = new int[n + 1];

            Arrays.fill(currentScore, -1);

            for (int col = n - 1; col >= 0; col--) {

                char cell = board.get(row).charAt(col);

                if (cell == 'X') {
                    continue;
                }

                if (cell == 'S') {
                    currentScore[col] = 0;
                    currentWays[col] = 1;
                    continue;
                }

                int bestScore = Math.max(
                        nextScore[col],
                        Math.max(
                                currentScore[col + 1],
                                nextScore[col + 1]
                        )
                );

                if (bestScore == -1) {
                    continue;
                }

                long totalWays = 0;

                if (nextScore[col] == bestScore) {
                    totalWays += nextWays[col];
                }

                if (currentScore[col + 1] == bestScore) {
                    totalWays += currentWays[col + 1];
                }

                if (nextScore[col + 1] == bestScore) {
                    totalWays += nextWays[col + 1];
                }

                int cellValue = (cell == 'E') ? 0 : (cell - '0');

                currentScore[col] = bestScore + cellValue;
                currentWays[col] = (int) (totalWays % MOD);
            }

            nextScore = currentScore;
            nextWays = currentWays;
        }

        if (nextScore[0] == -1) {
            return new int[]{0, 0};
        }

        return new int[]{nextScore[0], nextWays[0]};
    }
}
