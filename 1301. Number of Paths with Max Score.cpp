class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {

        const int MOD = 1000000007;

        int n = board.size();

        // DP for the next row
        vector<int> nextRowScore(n + 1, -1);
        vector<int> nextRowWays(n + 1, 0);

        for (int row = n - 1; row >= 0; row--) {

            // DP for the current row
            vector<int> currentRowScore(n + 1, -1);
            vector<int> currentRowWays(n + 1, 0);

            for (int col = n - 1; col >= 0; col--) {

                char cell = board[row][col];

                // Blocked cell
                if (cell == 'X') {
                    continue;
                }

                // Starting point
                if (cell == 'S') {
                    currentRowScore[col] = 0;
                    currentRowWays[col] = 1;
                    continue;
                }

                // Best score from:
                // Down, Right, Diagonal
                int bestScore = max({
                    nextRowScore[col],
                    currentRowScore[col + 1],
                    nextRowScore[col + 1]
                });

                if (bestScore == -1) {
                    continue;
                }

                long long totalWays = 0;

                if (nextRowScore[col] == bestScore) {
                    totalWays += nextRowWays[col];
                }

                if (currentRowScore[col + 1] == bestScore) {
                    totalWays += currentRowWays[col + 1];
                }

                if (nextRowScore[col + 1] == bestScore) {
                    totalWays += nextRowWays[col + 1];
                }

                int cellValue = (cell == 'E') ? 0 : (cell - '0');

                currentRowScore[col] = bestScore + cellValue;
                currentRowWays[col] = totalWays % MOD;
            }

            nextRowScore = move(currentRowScore);
            nextRowWays = move(currentRowWays);
        }

        if (nextRowScore[0] == -1) {
            return {0, 0};
        }

        return {
            nextRowScore[0],
            nextRowWays[0]
        };
    }
};
