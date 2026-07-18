class Solution:
    def findGCD(self, nums):
        mn = min(nums)
        mx = max(nums)

        while mx != 0:
            temp = mx
            mx = mn % mx
            mn = temp

        return mn
