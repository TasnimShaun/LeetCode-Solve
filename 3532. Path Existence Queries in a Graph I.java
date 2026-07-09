class Solution {

    public boolean[] pathExistenceQueries(
            int n,
            int[] nums,
            int maxDiff,
            int[][] queries
    ) {

        // Component ID for each index
        int[] componentId = new int[n];

        // Assign component IDs
        for (int index = 1; index < n; index++) {

            if (nums[index] - nums[index - 1] <= maxDiff) {

                componentId[index] =
                        componentId[index - 1];

            } else {

                componentId[index] =
                        componentId[index - 1] + 1;
            }
        }

        boolean[] result =
                new boolean[queries.length];

        // Answer each query
        for (int i = 0; i < queries.length; i++) {

            int leftIndex = queries[i][0];
            int rightIndex = queries[i][1];

            result[i] =
                    componentId[leftIndex] ==
                    componentId[rightIndex];
        }

        return result;
    }
}
