class Solution:
    def shiftGrid(self, grid, k):
        row = len(grid)
        column = len(grid[0])
        total = row * column

        k %= total

        answer = [[0] * column for _ in range(row)]

        for i in range(row):
            for j in range(column):

                previous_index = i * column + j

                new_index = (previous_index + k) % total

                new_row = new_index // column
                new_column = new_index % column

                answer[new_row][new_column] = grid[i][j]

        return answer
