class Solution {
public:
    static constexpr int MAX_GCD = 200;
    static constexpr int MOD = 1000000007;

    int subsequencePairCount(
        vector<int>& nums
    ) {

        static int dp[MAX_GCD + 1][MAX_GCD + 1];
        static int nextDp[MAX_GCD + 1][MAX_GCD + 1];

        memset(dp, 0, sizeof(dp));

        dp[0][0] = 1;

        for (int number : nums) {

            memset(nextDp, 0, sizeof(nextDp));

            for (int gcdFirst = 0;
                 gcdFirst <= MAX_GCD;
                 gcdFirst++) {

                for (int gcdSecond = 0;
                     gcdSecond <= MAX_GCD;
                     gcdSecond++) {

                    int currentWays =
                        dp[gcdFirst][gcdSecond];

                    if (currentWays == 0) {
                        continue;
                    }

                    // Option 1:
                    // Ignore current number
                    nextDp[gcdFirst][gcdSecond] =
                        (nextDp[gcdFirst][gcdSecond]
                        + currentWays) % MOD;

                    // Option 2:
                    // Add to first subsequence
                    int nextFirstGcd =
                        (gcdFirst == 0)
                        ? number
                        : gcd(gcdFirst, number);

                    nextDp[nextFirstGcd][gcdSecond] =
                        (nextDp[nextFirstGcd][gcdSecond]
                        + currentWays) % MOD;

                    // Option 3:
                    // Add to second subsequence
                    int nextSecondGcd =
                        (gcdSecond == 0)
                        ? number
                        : gcd(gcdSecond, number);

                    nextDp[gcdFirst][nextSecondGcd] =
                        (nextDp[gcdFirst][nextSecondGcd]
                        + currentWays) % MOD;
                }
            }

            memcpy(dp, nextDp, sizeof(dp));
        }

        long long answer = 0;

        // Count pairs where both subsequences
        // have the same non-zero GCD.
        for (int gcdValue = 1;
             gcdValue <= MAX_GCD;
             gcdValue++) {

            answer =
                (answer + dp[gcdValue][gcdValue])
                % MOD;
        }

        return answer;
    }
};
