# 88. Merge Sorted Array

## Problem

You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

Merge `nums1` and `nums2` into a single array sorted in non-decreasing order.

The final sorted array should be stored inside `nums1`.

---

### Example 1

Input:
nums1 = [1,2,3,0,0,0]
m = 3
nums2 = [2,5,6]
n = 3

Output:
[1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

### Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

### Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

---

### Constraints

- nums1.length == m + n
- nums2.length == n
- -10^9 <= nums1[i], nums2[i] <= 10^9

---

## Approach

- Start from the end of both arrays.
- Compare the last valid elements.
- Place the larger element at the end of `nums1`.
- Move the corresponding pointer backward.
- Copy any remaining elements from `nums2`.

---

## Time Complexity

O(m + n)

## Space Complexity

O(1)

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        
        # last index  nums1 array
        last_index = m + n - 1
        # merge reverse order 
        while( m > 0  and n > 0):
            if(nums1[m-1] > nums2[n-1]):
                nums1[last_index] = nums1[m-1]
                m -= 1
            else:
                nums1[last_index] = nums2[n-1]
                n-=1     
            last_index -= 1
       #  fill nums1 with leftover nums2 elements
        while(n > 0):
            nums1[last_index] = nums2[n-1]
            n -= 1
            last_index -= 1

        
