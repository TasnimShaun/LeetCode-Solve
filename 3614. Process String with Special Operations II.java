class Solution {

    public char processStr(
            String inputString,
            long targetIndex) {

        int stringLength =
                inputString.length();

        long[] processedLengths =
                new long[stringLength];

        long currentLength = 0;

        // Forward pass
        for (int currentIndex = 0;
             currentIndex < stringLength;
             currentIndex++) {

            char currentCharacter =
                    inputString.charAt(
                            currentIndex
                    );

            if (currentCharacter >= 'a' &&
                currentCharacter <= 'z') {

                currentLength++;
            }
            else if (
                    currentCharacter == '*') {

                if (currentLength > 0) {

                    currentLength--;
                }
            }
            else if (
                    currentCharacter == '#') {

                currentLength *= 2;
            }

            processedLengths[currentIndex] =
                    currentLength;
        }

        if (targetIndex >= currentLength) {

            return '.';
        }

        // Backward pass
        for (int currentIndex =
                 stringLength - 1;
             currentIndex >= 0;
             currentIndex--) {

            char currentCharacter =
                    inputString.charAt(
                            currentIndex
                    );

            long lengthBeforeOperation =
                    (currentIndex == 0)
                    ? 0
                    : processedLengths[
                        currentIndex - 1
                    ];

            if (currentCharacter >= 'a' &&
                currentCharacter <= 'z') {

                if (targetIndex ==
                    lengthBeforeOperation) {

                    return currentCharacter;
                }
            }
            else if (
                    currentCharacter == '#') {

                if (lengthBeforeOperation > 0) {

                    targetIndex %=
                            lengthBeforeOperation;
                }
            }
            else if (
                    currentCharacter == '%') {

                targetIndex =
                        lengthBeforeOperation
                        - 1
                        - targetIndex;
            }
        }

        return '.';
    }
}
