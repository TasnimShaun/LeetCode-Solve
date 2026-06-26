class Solution {
public:
    long long countMajoritySubarrays(
        vector<int>& numbers,
        int targetValue
    ) {

        int arraySize = numbers.size();

        long long majoritySubarrayCount = 0;

        // Convert:
        // targetValue -> +1
        // others      -> -1
        for (int index = 0;
             index < arraySize;
             index++) {

            if (numbers[index] == targetValue) {

                numbers[index] = 1;
            }
            else {

                numbers[index] = -1;
            }
        }

        // Prefix sum array
        vector<int> prefixSum(arraySize);

        prefixSum[0] = numbers[0];

        for (int index = 1;
             index < arraySize;
             index++) {

            prefixSum[index] =
                prefixSum[index - 1] +
                numbers[index];
        }

        // Shift is used because
        // prefix sums can be negative
        int balanceShift = arraySize;

        // Frequency of prefix sums
        vector<int> prefixFrequency(
            2 * arraySize + 1,
            0
        );

        // Initial prefix sum = 0
        prefixFrequency[balanceShift] = 1;

        long long validPrefixCount = 0;

        int previousPrefixSum = 0;

        for (int index = 0;
             index < arraySize;
             index++) {

            if (prefixSum[index] >
                previousPrefixSum) {

                validPrefixCount +=
                    prefixFrequency[
                        previousPrefixSum +
                        balanceShift
                    ];
            }
            else {

                validPrefixCount -=
                    prefixFrequency[
                        prefixSum[index] +
                        balanceShift
                    ];
            }

            majoritySubarrayCount +=
                validPrefixCount;

            prefixFrequency[
                prefixSum[index] +
                balanceShift
            ]++;

            previousPrefixSum =
                prefixSum[index];
        }

        return majoritySubarrayCount;
    }
};
