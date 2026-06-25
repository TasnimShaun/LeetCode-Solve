/**
 * @param {number[]} numbers
 * @param {number} targetValue
 * @return {number}
 */
var countMajoritySubarrays = function(
    numbers,
    targetValue
) {

    const arraySize = numbers.length;

    // Stores frequency of balance values
    const balanceFrequency =
        new Array(
            2 * arraySize + 1
        ).fill(0);

    // Initial balance = 0
    balanceFrequency[arraySize] = 1;

    let currentBalance =
        arraySize;

    let validPrefixCount = 0;

    let majoritySubarrayCount = 0;

    for (const currentNumber of numbers) {

        if (
            currentNumber ===
            targetValue
        ) {

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
};
