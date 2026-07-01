class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();

        if (grid[0][0] || grid[n - 1][n - 1])
            return 0;

        queue<pair<int, int>> q;

        for (int row = 0; row < n; row++) {

            for (int col = 0; col < n; col++) {

                if (grid[row][col])
                    q.push({row, col});
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Multi-source BFS
        while (!q.empty()) {

            auto [row, col] = q.front();
            q.pop();

            int distance = grid[row][col];

            for (int i = 0; i < 4; i++) {

                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 0) {

                    grid[newRow][newCol] = distance + 1;
                    q.push({newRow, newCol});
                }
            }
        }

        priority_queue<tuple<int, int, int>> pq;

        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {

            auto [safe, row, col] = pq.top();
            pq.pop();

            if (row == n - 1 && col == n - 1)
                return safe - 1;

            for (int i = 0; i < 4; i++) {

                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] > 0) {

                    pq.push({min(safe, grid[newRow][newCol]), newRow, newCol});

                    // visited
                    grid[newRow][newCol] *= -1;
                }
            }
        }

        return 0;
    }
};
