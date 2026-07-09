class Solution:
    def pathExistenceQueries(
        self,
        n: int,
        nums: List[int],
        maxDiff: int,
        queries: List[List[int]]
    ) -> List[bool]:

        # Component ID for each index
        component_id = [0] * n

        # Assign component IDs
        for index in range(1, n):

            if nums[index] - nums[index - 1] <= maxDiff:

                component_id[index] = (
                    component_id[index - 1]
                )

            else:

                component_id[index] = (
                    component_id[index - 1] + 1
                )

        result = []

        # Answer each query
        for left_index, right_index in queries:

            result.append(
                component_id[left_index] ==
                component_id[right_index]
            )

        return result
