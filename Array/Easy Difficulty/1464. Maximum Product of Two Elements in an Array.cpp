/*
Question:Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
Example 3:

Input: nums = [3,7]
Output: 12
  */

// optimal solution 
// time complexity O(n)
// space complexity O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int large = INT_MIN;
        int second_large = INT_MIN;
        int n = nums.size();
        for( int i = 0; i<n;i++)
        {
            if( nums[i] >= large)
            {
                second_large = large;
                large = nums[i];
            }
            else if( nums[i] > second_large)
            {
                second_large = nums[i];
            }
        }
        return( second_large - 1) * (large -1);
    }
};

// sorting solution 
// time complexity O(n log n)

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};

// brute force solution 
// time complexity O(n^2)

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int maximum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int product = (nums[i] - 1) * (nums[j] - 1);

                maximum = max(maximum, product);
            }
        }

        return maximum;
    }
};

