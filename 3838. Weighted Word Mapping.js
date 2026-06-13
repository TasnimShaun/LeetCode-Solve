/**
 * @param {string[]} wordList
 * @param {number[]} letterWeights
 * @return {string}
 */
var mapWordWeights = function(wordList, letterWeights) {

    // Stores the final encoded string
    let encodedResult = "";

    // Process each word
    for (const currentWord of wordList) {

        let totalWeight = 0;

        // Calculate the total weight of the current word
        for (const currentCharacter of currentWord) {

            totalWeight +=
                letterWeights[
                    currentCharacter.charCodeAt(0) - 97
                ];
        }

        // Reduce the weight to the range [0, 25]
        const mappedValue =
            totalWeight % 26;

        // Convert the value into a character
        encodedResult +=
            String.fromCharCode(
                'z'.charCodeAt(0) - mappedValue
            );
    }

    return encodedResult;
};
