/*
Question : Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.
A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).
Example 1:
Input: nums = [0,2,1,5,3,4]
Output: [0,1,2,4,5,3]
Explanation: The array ans is built as follows: 
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    = [0,1,2,4,5,3]
Example 2:
Input: nums = [5,0,1,2,3,4]
Output: [4,5,0,1,2,3]
Explanation: The array ans is built as follows:
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
    = [4,5,0,1,2,3]

    # Approach

The problem asks us to build a new array `ans` such that:

`ans[i] = nums[nums[i]]`

### Steps

1. Create a new array `ans` of the same size as `nums`.
2. Traverse the array from index `0` to `n - 1`.
3. For each index `i`:

   * Store `nums[i]` in a variable (`first`).
   * Use `first` as an index to access `nums[first]`.
   * Store the obtained value in `ans[i]`.
4. After processing all indices, return the `ans` array.

### Intuition

Each value in `nums` is guaranteed to be a valid index because `nums` is a permutation of the integers from `0` to `n - 1`.

So, for every index:

* First jump: `i → nums[i]`
* Second jump: `nums[i] → nums[nums[i]]`

The value reached after the second jump becomes the answer for that index.

### Complexity Analysis

* **Time Complexity:** `O(n)`

  * We traverse the array only once.

* **Space Complexity:** `O(n)`

  * An extra array `ans` of size `n` is used to store the result.

*/

  class Solution {
  public:
    vector<int> buildArray(vector<int>& nums) {
        
        int first,second  = 0;
        vector<int> ans(nums.size());
        for(int i = 0 ; i < nums.size();i++)
        {
            first = nums[i];
            second = nums[first];
            ans[i] = second;
        }
         return ans;

    }
};

