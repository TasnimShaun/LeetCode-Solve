class Solution {
public:

    int minElement(vector<int>& numbers) {

        // Stores the minimum digit sum
        int minimumDigitSum = INT_MAX;

        // Traverse all numbers in the array
        for (int currentNumber : numbers) {

            int digitSum = 0;

            // Calculate sum of digits
            while (currentNumber > 0) {

                digitSum += currentNumber % 10;

                currentNumber /= 10;
            }

            // Update minimum digit sum
            minimumDigitSum = min(minimumDigitSum, digitSum);
        }

        return minimumDigitSum;
    }
};
