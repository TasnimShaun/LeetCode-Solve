class Solution {

    public int removeCoveredIntervals(
            int[][] intervals
    ) {

        Arrays.sort(
                intervals,
                (first, second) -> {

                    if (first[0] == second[0]) {
                        return second[1] - first[1];
                    }

                    return first[0] - second[0];
                }
        );

        int maxEnd = -1;

        int remaining = 0;

        for (int[] interval : intervals) {

            if (interval[1] > maxEnd) {

                remaining++;

                maxEnd = interval[1];
            }
        }

        return remaining;
    }
}
