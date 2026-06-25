class Solution {

    public int countMajoritySubarrays(
            int[] numbers,
            int targetValue) {

        int arraySize = numbers.length;

        // Stores frequency of balance values
        int[] balanceFrequency =
                new int[
                        2 * arraySize + 1
                ];

        // Initial balance = 0
        balanceFrequency[arraySize] = 1;

        int currentBalance =
                arraySize;

        int validPrefixCount = 0;

        int majoritySubarrayCount = 0;

        for (int currentNumber : numbers) {

            if (currentNumber ==
                targetValue) {

                // Count prefixes with
                // the same balance
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
}
