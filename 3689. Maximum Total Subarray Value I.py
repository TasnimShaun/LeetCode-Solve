class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:

        # প্রথম element-কে initial minimum এবং maximum ধরা হচ্ছে
        minimum_ = maximum_ = nums[0]

        # পুরো array traverse করে minimum এবং maximum বের করছি
        for i in nums:
            minimum_ = min(minimum_, i)  # minimum update
            maximum_ = max(maximum_, i)  # maximum update

        # answer = (global max - global min) * k
        return (maximum_ - minimum_) * k
