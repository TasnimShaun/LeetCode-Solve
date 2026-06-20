/**
 * @param {number} n
 * @param {number[][]} restrictions
 * @return {number}
 */
var maxBuilding = function (n, restrictions) {

    // Add building 1 and building n
    restrictions.push([1, 0]);
    restrictions.push([n, n - 1]);

    // Sort by building index
    restrictions.sort((a, b) => a[0] - b[0]);

    const m = restrictions.length;

    // Left to Right pass
    for (let i = 1; i < m; i++) {

        restrictions[i][1] = Math.min(
            restrictions[i][1],
            restrictions[i - 1][1] +
            (restrictions[i][0] - restrictions[i - 1][0])
        );
    }

    // Right to Left pass
    for (let i = m - 2; i >= 0; i--) {

        restrictions[i][1] = Math.min(
            restrictions[i][1],
            restrictions[i + 1][1] +
            (restrictions[i + 1][0] - restrictions[i][0])
        );
    }

    let answer = 0;

    // Find maximum possible peak
    for (let i = 1; i < m; i++) {

        const [x1, h1] = restrictions[i - 1];
        const [x2, h2] = restrictions[i];

        const dist = x2 - x1;

        const peak = Math.floor((h1 + h2 + dist) / 2);

        answer = Math.max(answer, peak);
    }

    return answer;
};
