class Solution {
public:
    vector<int> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {

        // Store (value, original index)
        vector<pair<int, int>> sortedNodes;

        sortedNodes.reserve(n);

        for (int index = 0; index < n; index++) {
            sortedNodes.push_back(
                {nums[index], index}
            );
        }

        sort(
            sortedNodes.begin(),
            sortedNodes.end()
        );

        // Position of each original index
        vector<int> position(n);

        // Sorted values
        vector<int> sortedValues(n);

        for (int index = 0; index < n; index++) {

            sortedValues[index] =
                sortedNodes[index].first;

            position[
                sortedNodes[index].second
            ] = index;
        }

        // Number of levels for Binary Lifting
        int maxPower = 1;

        while ((1 << maxPower) <= n) {
            maxPower++;
        }

        vector<vector<int>> jump(
            maxPower,
            vector<int>(n)
        );

        int rightPointer = 0;

        // Build first jump table
        for (int leftPointer = 0;
             leftPointer < n;
             leftPointer++) {

            if (rightPointer < leftPointer) {
                rightPointer = leftPointer;
            }

            while (
                rightPointer + 1 < n &&
                sortedValues[rightPointer + 1] -
                    sortedValues[leftPointer]
                    <= maxDiff
            ) {
                rightPointer++;
            }

            jump[0][leftPointer] =
                rightPointer;
        }

        // Binary Lifting table
        for (int power = 1;
             power < maxPower;
             power++) {

            for (int index = 0;
                 index < n;
                 index++) {

                jump[power][index] =
                    jump[power - 1][
                        jump[power - 1][index]
                    ];
            }
        }

        vector<int> answer;

        answer.reserve(
            queries.size()
        );

        for (const auto& query : queries) {

            int left =
                position[query[0]];

            int right =
                position[query[1]];

            if (left > right) {
                swap(left, right);
            }

            if (left == right) {

                answer.push_back(0);

                continue;
            }

            int current = left;

            int minimumSteps = 0;

            // Binary Lifting
            for (int power = maxPower - 1;
                 power >= 0;
                 power--) {

                if (
                    jump[power][current] <
                    right
                ) {

                    current =
                        jump[power][current];

                    minimumSteps +=
                        (1 << power);
                }
            }

            if (jump[0][current] >= right) {

                answer.push_back(
                    minimumSteps + 1
                );

            } else {

                answer.push_back(-1);
            }
        }

        return answer;
    }
};
