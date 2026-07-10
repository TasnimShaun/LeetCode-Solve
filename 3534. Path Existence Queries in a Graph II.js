/**
 * @param {number} n
 * @param {number[]} nums
 * @param {number} maxDiff
 * @param {number[][]} queries
 * @return {number[]}
 */
var pathExistenceQueries = function (
    n,
    nums,
    maxDiff,
    queries
) {

    const nodes = [];

    for (let i = 0; i < n; i++) {
        nodes.push([nums[i], i]);
    }

    nodes.sort((a, b) => a[0] - b[0]);

    const position = new Array(n);
    const values = new Array(n);

    for (let i = 0; i < n; i++) {
        values[i] = nodes[i][0];
        position[nodes[i][1]] = i;
    }

    let LOG = 1;

    while ((1 << LOG) <= n) {
        LOG++;
    }

    const jump = Array.from(
        { length: LOG },
        () => new Array(n).fill(0)
    );

    let right = 0;

    for (let left = 0; left < n; left++) {

        if (right < left) {
            right = left;
        }

        while (
            right + 1 < n &&
            values[right + 1] -
                values[left] <=
                maxDiff
        ) {
            right++;
        }

        jump[0][left] = right;
    }

    for (let power = 1; power < LOG; power++) {

        for (let i = 0; i < n; i++) {

            jump[power][i] =
                jump[power - 1][
                    jump[power - 1][i]
                ];
        }
    }

    const answer = [];

    for (const [u, v] of queries) {

        let left = position[u];
        let rightPos = position[v];

        if (left > rightPos) {
            [left, rightPos] =
                [rightPos, left];
        }

        if (left === rightPos) {
            answer.push(0);
            continue;
        }

        let current = left;
        let distance = 0;

        for (
            let power = LOG - 1;
            power >= 0;
            power--
        ) {

            if (
                jump[power][current] <
                rightPos
            ) {

                current =
                    jump[power][current];

                distance +=
                    (1 << power);
            }
        }

        if (
            jump[0][current] >=
            rightPos
        ) {
            answer.push(distance + 1);
        } else {
            answer.push(-1);
        }
    }

    return answer;
};
