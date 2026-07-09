class Solution {
public:
    vector<bool> pathExistenceQueries(
        int size,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {

        // Component ID for each index
        vector<int> componentId(size);

        componentId[0] = 0;

        // Assign component IDs
        for (int index = 1; index < size; index++) {

            if (nums[index] - nums[index - 1] <= maxDiff) {

                componentId[index] =
                    componentId[index - 1];
            }
            else {

                componentId[index] =
                    componentId[index - 1] + 1;
            }
        }

        vector<bool> result;

        result.reserve(queries.size());

        // Answer each query
        for (const auto& query : queries) {

            int leftIndex = query[0];
            int rightIndex = query[1];

            result.push_back(
                componentId[leftIndex] ==
                componentId[rightIndex]
            );
        }

        return result;
    }
};
