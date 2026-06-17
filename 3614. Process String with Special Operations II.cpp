class Solution {
public:

    char processStr(
        string inputString,
        long long targetIndex
    ) {

        int stringLength =
            inputString.size();

        // Stores the length of the
        // processed string after each operation
        vector<long long> processedLengths(
            stringLength
        );

        long long currentLength = 0;

        // Forward pass:
        // Compute the length after each operation
        for (int currentIndex = 0;
             currentIndex < stringLength;
             currentIndex++) {

            char currentCharacter =
                inputString[currentIndex];

            if (currentCharacter >= 'a' &&
                currentCharacter <= 'z') {

                currentLength++;
            }
            else if (currentCharacter == '*') {

                if (currentLength > 0) {
                    currentLength--;
                }
            }
            else if (currentCharacter == '#') {

                currentLength *= 2;
            }
            else if (currentCharacter == '%') {

                // Length does not change
            }

            processedLengths[currentIndex] =
                currentLength;
        }

        // If k is outside the final string
        if (targetIndex >= currentLength) {
            return '.';
        }

        // Backward pass:
        // Trace the character at index k
        for (int currentIndex =
                 stringLength - 1;
             currentIndex >= 0;
             currentIndex--) {

            char currentCharacter =
                inputString[currentIndex];

            long long lengthAfterOperation =
                processedLengths[currentIndex];

            long long lengthBeforeOperation =
                (currentIndex == 0)
                ? 0
                : processedLengths[
                    currentIndex - 1
                  ];

            // Letter insertion
            if (currentCharacter >= 'a' &&
                currentCharacter <= 'z') {

                if (targetIndex ==
                    lengthBeforeOperation) {

                    return currentCharacter;
                }
            }

            // String duplication
            else if (
                currentCharacter == '#'
            ) {

                if (lengthBeforeOperation > 0) {

                    targetIndex %=
                        lengthBeforeOperation;
                }
            }

            // String reversal
            else if (
                currentCharacter == '%'
            ) {

                targetIndex =
                    lengthBeforeOperation -
                    1 -
                    targetIndex;
            }

            // '*' does not need
            // special handling here
        }

        return '.';
    }
};
