class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> cost(rows, vector<int>(cols, INT_MAX));

        deque<pair<int, int>> dq;

        cost[0][0] = grid[0][0];
        dq.push_front({0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!dq.empty()) {

            auto [row, col] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; i++) {

                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow < 0 || newRow >= rows ||
                    newCol < 0 || newCol >= cols)
                    continue;

                int newHealthLoss = cost[row][col] + grid[newRow][newCol];

                if (newHealthLoss < cost[newRow][newCol]) {

                    cost[newRow][newCol] = newHealthLoss;

                    if (grid[newRow][newCol] == 0)
                        dq.push_front({newRow, newCol});
                    else
                        dq.push_back({newRow, newCol});
                }
            }
        }

        return cost[rows - 1][cols - 1] < health;
    }
};
