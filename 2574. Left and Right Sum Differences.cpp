class Solution {
public:

    vector<int> leftRightDifference(vector<int>& numbers) {

        int arraySize = numbers.size();

        // Calculate total sum of all elements
        int remainingRightSum = 0;

        for (int currentNumber : numbers) {
            remainingRightSum += currentNumber;
        }

        // Sum of elements to the left of current index
        int currentLeftSum = 0;

        vector<int> differences(arraySize);

        for (int index = 0; index < arraySize; index++) {

            // Remove current element from right sum
            remainingRightSum -= numbers[index];

            // Store absolute difference
            differences[index] =
                abs(currentLeftSum - remainingRightSum);

            // Add current element to left sum
            currentLeftSum += numbers[index];
        }

        return differences;
    }
};
