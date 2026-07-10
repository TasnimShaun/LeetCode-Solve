class Solution {

    public int[] pathExistenceQueries(
            int n,
            int[] nums,
            int maxDiff,
            int[][] queries
    ) {

        int[][] nodes = new int[n][2];

        for (int i = 0; i < n; i++) {
            nodes[i][0] = nums[i];
            nodes[i][1] = i;
        }

        Arrays.sort(
                nodes,
                Comparator.comparingInt(a -> a[0])
        );

        int[] position = new int[n];
        int[] values = new int[n];

        for (int i = 0; i < n; i++) {
            values[i] = nodes[i][0];
            position[nodes[i][1]] = i;
        }

        int maxPower = 1;

        while ((1 << maxPower) <= n) {
            maxPower++;
        }

        int[][] jump = new int[maxPower][n];

        int rightPointer = 0;

        // Build first jump table
        for (int leftPointer = 0; leftPointer < n; leftPointer++) {

            if (rightPointer < leftPointer) {
                rightPointer = leftPointer;
            }

            while (
                    rightPointer + 1 < n &&
                    values[rightPointer + 1] - values[leftPointer] <= maxDiff
            ) {
                rightPointer++;
            }

            jump[0][leftPointer] = rightPointer;
        }

        // Binary Lifting table
        for (int power = 1; power < maxPower; power++) {

            for (int i = 0; i < n; i++) {

                jump[power][i] =
                        jump[power - 1][
                                jump[power - 1][i]
                        ];
            }
        }

        int[] answer = new int[queries.length];

        for (int i = 0; i < queries.length; i++) {

            int left = position[queries[i][0]];
            int rightPosition = position[queries[i][1]];

            if (left > rightPosition) {
                int temp = left;
                left = rightPosition;
                rightPosition = temp;
            }

            if (left == rightPosition) {
                answer[i] = 0;
                continue;
            }

            int current = left;
            int minimumSteps = 0;

            for (int power = maxPower - 1; power >= 0; power--) {

                if (jump[power][current] < rightPosition) {

                    current = jump[power][current];

                    minimumSteps += (1 << power);
                }
            }

            if (jump[0][current] >= rightPosition) {
                answer[i] = minimumSteps + 1;
            } else {
                answer[i] = -1;
            }
        }

        return answer;
    }
}
