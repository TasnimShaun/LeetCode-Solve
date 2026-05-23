class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();

        // Count how many times the order decreases
        int count = 0;

        for (int i = 0; i < n; i++) {

            // Compare current element with next element
            // (i + 1) % n ensures circular comparison
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }

            // More than one decreasing point means
            // the array cannot be sorted and rotated
            if (count > 1) {
                return false;
            }
        }

        return true;
    }
};
