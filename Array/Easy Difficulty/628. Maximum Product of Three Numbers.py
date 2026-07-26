""" 
Question : Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6
"""

# optimal solution -> O(n)
class Solution:
    def maximumProduct(self, nums: list[int]) -> int:

        largest = float('-inf')
        second_largest = float('-inf')
        third_largest = float('-inf')

        smallest = float('inf')
        second_smallest = float('inf')

        for num in nums:

            # Update largest three numbers
            if num > largest:
                third_largest = second_largest
                second_largest = largest
                largest = num

            elif num > second_largest:
                third_largest = second_largest
                second_largest = num

            elif num > third_largest:
                third_largest = num

            # Update smallest two numbers
            if num < smallest:
                second_smallest = smallest
                smallest = num

            elif num < second_smallest:
                second_smallest = num

        product1 = largest * second_largest * third_largest
        product2 = largest * smallest * second_smallest

        return max(product1, product2)


# Sorting Solution — O(n log n)

class Solution:
    def maximumProduct(self, nums: list[int]) -> int:
        nums.sort()

        n = len(nums)

        product1 = nums[n - 1] * nums[n - 2] * nums[n - 3]
        product2 = nums[0] * nums[1] * nums[n - 1]

        return max(product1, product2)


