class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();

        // Step 1: Find the index of the smallest element (rotation point)
        int left = 0, right = size - 1;

        while (left < right) {
            int middle = left + (right - left) / 2;

            // If middle element is greater than the last element,
            // the rotation point lies on the right side
            if (nums[middle] > nums[size - 1])
                left = middle + 1;
            else
                right = middle;
        }

        int rotationIndex = left;

        // Step 2: Perform binary search on the virtually sorted array
        left = 0;
        right = size - 1;

        while (left <= right) {
            int middle = left + (right - left) / 2;

            // Convert virtual index to actual index in rotated array
            int actualIndex = (middle + rotationIndex) % size;

            // Target found
            if (nums[actualIndex] == target)
                return actualIndex;

            // Move to the right half
            if (nums[actualIndex] < target)
                left = middle + 1;
            // Move to the left half
            else
                right = middle - 1;
        }

        // Target not found
        return -1;
    }
};
