/*
Question: Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6
  */

// optimize solution 
// time complexity -> O(n)
// Space complexity -> 0(1)

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int largest = INT_MIN, second_largest =INT_MIN , third_largest = INT_MIN, smallest = INT_MAX, second_smallest = INT_MAX;
        for(int i = 0;i<n;i++)
        {
            if(nums[i] > largest)
            {
                third_largest = second_largest;
                second_largest = largest;
                largest = nums[i];
            }
            else if(nums[i] > second_largest)
            {
                third_largest = second_largest;
                second_largest = nums[i];
            }
            
            else if (nums[i] > third_largest)
            {
                third_largest = nums[i];
            }
            if(nums[i] < smallest)
            {
                second_smallest = smallest;
                smallest = nums[i];
            }
            else if(nums[i] < second_smallest)
            {
                second_smallest = nums[i];
            }

        } 
        int product1 = largest * second_largest * third_largest;
        int product2 = largest * smallest * second_smallest;

        return max(product1, product2);
    }
};

// solution by sorting 
// easy approach 
// time complexity -> O(n log n)

class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int product1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int product2 = nums[0] * nums[1] * nums[n - 1];
        return max(product1, product2);
    }
};
