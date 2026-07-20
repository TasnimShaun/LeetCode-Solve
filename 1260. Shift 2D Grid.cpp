class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int column = grid[0].size();
        int total = row * column;

        k %= total;
        vector< vector < int >> answer(row, vector<int > (column));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {

                int previous_index = i * column + j;

                int new_index = (previous_index + k) % total;

                int new_row = new_index / column;
                int new_column = new_index % column;

                answer[new_row][new_column] = grid[i][j];
            }
        }

        return answer;
     }
};
