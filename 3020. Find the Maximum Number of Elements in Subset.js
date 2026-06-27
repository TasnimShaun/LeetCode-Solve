/**
 * @param {number[]} numbers
 * @return {number}
 */
var maximumLength = function(numbers) {

    // Stores the frequency of each number
    const frequencyMap = new Map();

    for (const currentNumber of numbers) {

        frequencyMap.set(
            currentNumber,
            (frequencyMap.get(currentNumber) || 0) + 1
        );
    }

    let maximumSequenceLength = 1;

    // Handle the special case for number 1
    if (frequencyMap.has(1)) {

        const oneCount = frequencyMap.get(1);

        // The final length must be odd
        maximumSequenceLength = Math.max(
            maximumSequenceLength,
            oneCount % 2 === 1
                ? oneCount
                : oneCount - 1
        );
    }

    // Try every unique number as the starting value
    for (const [startingValue] of frequencyMap) {

        if (startingValue === 1) {
            continue;
        }

        let currentValue = startingValue;

        let currentLength = 0;

        while (frequencyMap.has(currentValue)) {

            // Need at least two occurrences
            // to continue the chain
            if (
                frequencyMap.get(currentValue) >= 2
            ) {

                currentLength += 2;

                currentValue =
                    currentValue * currentValue;
            }
            else {

                // Last occurrence
                currentLength++;

                break;
            }
        }

        // Final answer must be odd
        if (currentLength % 2 === 0) {

            currentLength--;
        }

        maximumSequenceLength = Math.max(
            maximumSequenceLength,
            currentLength
        );
    }

    return maximumSequenceLength;
};
