class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {

        int row = grid.length;
        int column = grid[0].length;
        int total = row * column;

        k %= total;

        List<List<Integer>> answer = new ArrayList<>();

        for (int i = 0; i < row; i++) {
            List<Integer> temp = new ArrayList<>();

            for (int j = 0; j < column; j++) {
                temp.add(0);
            }

            answer.add(temp);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {

                int previousIndex = i * column + j;

                int newIndex = (previousIndex + k) % total;

                int newRow = newIndex / column;
                int newColumn = newIndex % column;

                answer.get(newRow).set(newColumn, grid[i][j]);
            }
        }

        return answer;
    }
}
