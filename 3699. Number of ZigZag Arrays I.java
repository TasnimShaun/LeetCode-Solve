import java.util.*;

class Solution {
    private static final int MOD = 1000000007;

    public int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        long[] dp = new long[m];
        Arrays.fill(dp, 1);

        for (int len = 2; len <= n; len++) {

            for (int i = 0, j = m - 1; i < j; i++, j--) {
                long temp = dp[i];
                dp[i] = dp[j];
                dp[j] = temp;
            }

            long prefixSum = 0;

            for (int i = 0; i < m; i++) {
                long current = dp[i];

                dp[i] = prefixSum;

                prefixSum = (prefixSum + current) % MOD;
            }
        }

        long totalWays = 0;

        for (long ways : dp) {
            totalWays = (totalWays + ways) % MOD;
        }

        return (int)((totalWays * 2) % MOD);
    }
}
