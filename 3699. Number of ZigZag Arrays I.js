const MOD = 1000000007;

/**
 * @param {number} n
 * @param {number} l
 * @param {number} r
 * @return {number}
 */
var zigZagArrays = function(n, l, r) {
    const m = r - l + 1;

    let dp = new Array(m).fill(1);

    for (let len = 2; len <= n; len++) {
        dp.reverse();

        let prefixSum = 0;

        for (let i = 0; i < m; i++) {
            const current = dp[i];

            dp[i] = prefixSum;

            prefixSum = (prefixSum + current) % MOD;
        }
    }

    let totalWays = 0;

    for (const ways of dp) {
        totalWays = (totalWays + ways) % MOD;
    }

    return (totalWays * 2) % MOD;
};
