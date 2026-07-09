/**
 * @param {number} n
 * @param {number[]} nums
 * @param {number} maxDiff
 * @param {number[][]} queries
 * @return {boolean[]}
 */
var pathExistenceQueries = function (
    n,
    nums,
    maxDiff,
    queries
) {

    // Component ID for each index
    const componentId =
        new Array(n).fill(0);

    // Assign component IDs
    for (let index = 1; index < n; index++) {

        if (
            nums[index] -
            nums[index - 1] <=
            maxDiff
        ) {

            componentId[index] =
                componentId[index - 1];

        } else {

            componentId[index] =
                componentId[index - 1] + 1;
        }
    }

    const result = [];

    // Answer each query
    for (const [leftIndex, rightIndex] of queries) {

        result.push(
            componentId[leftIndex] ===
            componentId[rightIndex]
        );
    }

    return result;
};
