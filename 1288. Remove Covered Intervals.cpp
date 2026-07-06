class Solution {
public:
    int removeCoveredIntervals(
        vector<vector<int>>& intervals
    ) {

        // Sort by:
        // 1. Start point (ascending)
        // 2. End point (descending) if starts are equal
        sort(
            intervals.begin(),
            intervals.end(),
            [](const vector<int>& firstInterval,
               const vector<int>& secondInterval) {

                if (firstInterval[0] ==
                    secondInterval[0]) {

                    return firstInterval[1] >
                           secondInterval[1];
                }

                return firstInterval[0] <
                       secondInterval[0];
            }
        );

        int farthestEnd = -1;

        int remainingIntervals = 0;

        for (const auto& interval : intervals) {

            int start = interval[0];
            int end = interval[1];

            // Not covered by any previous interval
            if (end > farthestEnd) {

                remainingIntervals++;

                farthestEnd = end;
            }
        }

        return remainingIntervals;
    }
};
