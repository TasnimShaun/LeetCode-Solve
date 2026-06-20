class Solution {
    public int maxBuilding(int n, int[][] restrictions) {

        List<int[]> list = new ArrayList<>();

        for (int[] r : restrictions) {
            list.add(r);
        }

        // Add building 1 and building n
        list.add(new int[]{1, 0});
        list.add(new int[]{n, n - 1});

        // Sort by building index
        list.sort((a, b) -> Integer.compare(a[0], b[0]));

        int m = list.size();

        // Left to Right pass
        for (int i = 1; i < m; i++) {

            int[] curr = list.get(i);
            int[] prev = list.get(i - 1);

            curr[1] = Math.min(
                curr[1],
                prev[1] + (curr[0] - prev[0])
            );
        }

        // Right to Left pass
        for (int i = m - 2; i >= 0; i--) {

            int[] curr = list.get(i);
            int[] next = list.get(i + 1);

            curr[1] = Math.min(
                curr[1],
                next[1] + (next[0] - curr[0])
            );
        }

        long answer = 0;

        // Find maximum peak between adjacent restrictions
        for (int i = 1; i < m; i++) {

            long x1 = list.get(i - 1)[0];
            long h1 = list.get(i - 1)[1];

            long x2 = list.get(i)[0];
            long h2 = list.get(i)[1];

            long dist = x2 - x1;

            long peak = (h1 + h2 + dist) / 2;

            answer = Math.max(answer, peak);
        }

        return (int) answer;
    }
}
