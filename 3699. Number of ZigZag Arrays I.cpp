class Solution {
public:
    static const int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> dp(m, 1);

        for (int len = 2; len <= n; len++) {
            reverse(dp.begin(), dp.end());

            long long prefixSum = 0;

            for (int i = 0; i < m; i++) {
                long long current = dp[i];

                dp[i] = prefixSum;

                prefixSum = (prefixSum + current) % MOD;
            }
        }

        long long totalWays = 0;

        for (long long ways : dp) {
            totalWays = (totalWays + ways) % MOD;
        }

        return (int)((totalWays * 2) % MOD);
    }
};
