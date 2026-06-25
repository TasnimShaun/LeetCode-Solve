class Solution {
public:

    long long countMajoritySubarrays(
        vector<int>& numbers,
        int targetValue
    ) {

        int arraySize = numbers.size();

        // Frequency of balance values
        vector<int> balanceFrequency(
            2 * arraySize + 1,
            0
        );

        // Initial balance = 0
        balanceFrequency[arraySize] = 1;

        int currentBalance = arraySize;

        long long validPrefixCount = 0;

        long long majoritySubarrayCount = 0;

        for (int currentNumber : numbers) {

            if (currentNumber == targetValue) {

                // Count prefixes with same balance
                validPrefixCount +=
                    balanceFrequency[
                        currentBalance
                    ];

                currentBalance++;

                balanceFrequency[
                    currentBalance
                ]++;
            }
            else {

                currentBalance--;

                validPrefixCount -=
                    balanceFrequency[
                        currentBalance
                    ];

                balanceFrequency[
                    currentBalance
                ]++;
            }

            majoritySubarrayCount +=
                validPrefixCount;
        }

        return majoritySubarrayCount;
    }
};
