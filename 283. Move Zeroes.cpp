class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // position where next non-zero element should go
        int j = 0;

        // traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // if current element is non-zero
            if (nums[i] != 0) {

                // move non-zero element to position j
                swap(nums[i], nums[j]);

                // next available position
                j++;
            }
        }
    }
};
