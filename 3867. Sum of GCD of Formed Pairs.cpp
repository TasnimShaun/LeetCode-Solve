class Solution {
public:
    long long gcdSum(
        vector<int>& nums
    ) {

        int size = nums.size();

        // Store gcd(value, maximum so far)
        vector<int> prefixGcd(size);

        int maximumValue = 0;

        for (int index = 0;
             index < size;
             index++) {

            maximumValue = max(
                maximumValue,
                nums[index]
            );

            prefixGcd[index] = gcd(
                nums[index],
                maximumValue
            );
        }

        // Sort the GCD values
        sort(
            prefixGcd.begin(),
            prefixGcd.end()
        );

        long long answer = 0;

        int leftIndex = 0;
        int rightIndex = size - 1;

        // Pair smallest with largest
        while (leftIndex < rightIndex) {

            answer += gcd(
                prefixGcd[leftIndex],
                prefixGcd[rightIndex]
            );

            leftIndex++;
            rightIndex--;
        }

        return answer;
    }
};
