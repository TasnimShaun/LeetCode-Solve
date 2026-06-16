/**
 * @param {string} inputString
 * @return {string}
 */
var processStr = function(inputString) {

    // Stores the processed string
    let processedString = "";

    for (const currentCharacter of inputString) {

        // If it is a lowercase letter,
        // append it to the result
        if (currentCharacter >= 'a' &&
            currentCharacter <= 'z') {

            processedString +=
                currentCharacter;
        }

        // Remove the last character
        else if (currentCharacter === '*') {

            if (processedString.length > 0) {

                processedString =
                    processedString.slice(
                        0,
                        processedString.length - 1
                    );
            }
        }

        // Duplicate the current string
        else if (currentCharacter === '#') {

            processedString +=
                processedString;
        }

        // Reverse the current string
        else if (currentCharacter === '%') {

            processedString =
                processedString
                    .split('')
                    .reverse()
                    .join('');
        }
    }

    return processedString;
};
