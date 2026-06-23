class Solution:
    MOD = 1000000007

    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        m = r - l + 1

        dp = [1] * m

        for _ in range(2, n + 1):
            dp.reverse()

            prefix_sum = 0

            for i in range(m):
                current = dp[i]

                dp[i] = prefix_sum

                prefix_sum = (prefix_sum + current) % self.MOD

        total_ways = sum(dp) % self.MOD

        return (total_ways * 2) % self.MOD
