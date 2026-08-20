class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> array1, array2;

        array1.reserve(nums.size());
        array2.reserve(nums.size());

        array1.push_back(nums[0]);

        array2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            if (array1.back() > array2.back()) {
                array1.push_back(nums[i]);
            } else {
                array2.push_back(nums[i]);
            }
        }

        vector<int> result;
        result.reserve(nums.size());

        result.insert(result.end(), array1.begin(), array1.end());

        result.insert(result.end(), array2.begin(), array2.end());

        return result;
    }
};
