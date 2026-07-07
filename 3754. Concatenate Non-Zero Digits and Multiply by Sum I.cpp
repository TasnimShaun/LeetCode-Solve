class Solution {
public:
    long long sumAndMultiply(int number) {

        long long newNumber = 0;

        long long digitSum = 0;

        // Find the highest place value
        int placeValue = 1;

        while (number / placeValue >= 10) {
            placeValue *= 10;
        }

        // Process digits from left to right
        while (placeValue > 0) {

            int currentDigit = number / placeValue;

            number %= placeValue;

            // Ignore leading zeros
            if (currentDigit != 0) {

                newNumber =
                    newNumber * 10 + currentDigit;

                digitSum += currentDigit;
            }

            placeValue /= 10;
        }

        return newNumber * digitSum;
    }
};
