/**
 * @param {string} inputString
 * @param {number} targetIndex
 * @return {string}
 */
var processStr = function(
    inputString,
    targetIndex
) {

    const stringLength =
        inputString.length;

    // Stores the processed string length
    // after each operation
    const processedLengths =
        new Array(stringLength);

    let currentLength = 0;

    // Forward pass
    for (let currentIndex = 0;
         currentIndex < stringLength;
         currentIndex++) {

        const currentCharacter =
            inputString[currentIndex];

        if (
            currentCharacter >= 'a' &&
            currentCharacter <= 'z'
        ) {

            currentLength++;
        }
        else if (
            currentCharacter === '*'
        ) {

            if (currentLength > 0) {

                currentLength--;
            }
        }
        else if (
            currentCharacter === '#'
        ) {

            currentLength *= 2;
        }

        processedLengths[currentIndex] =
            currentLength;
    }

    if (targetIndex >= currentLength) {

        return '.';
    }

    // Backward pass
    for (let currentIndex =
             stringLength - 1;
         currentIndex >= 0;
         currentIndex--) {

        const currentCharacter =
            inputString[currentIndex];

        const lengthBeforeOperation =
            currentIndex === 0
            ? 0
            : processedLengths[
                currentIndex - 1
              ];

        if (
            currentCharacter >= 'a' &&
            currentCharacter <= 'z'
        ) {

            if (
                targetIndex ===
                lengthBeforeOperation
            ) {

                return currentCharacter;
            }
        }
        else if (
            currentCharacter === '#'
        ) {

            if (
                lengthBeforeOperation > 0
            ) {

                targetIndex %=
                    lengthBeforeOperation;
            }
        }
        else if (
            currentCharacter === '%'
        ) {

            targetIndex =
                lengthBeforeOperation -
                1 -
                targetIndex;
        }
    }

    return '.';
};
