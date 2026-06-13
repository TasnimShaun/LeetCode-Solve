class Solution {

    public String mapWordWeights(
            String[] wordList,
            int[] letterWeights) {

        StringBuilder encodedResult =
                new StringBuilder();

        // Process each word
        for (String currentWord : wordList) {

            int totalWeight = 0;

            // Calculate total weight of the current word
            for (char currentCharacter :
                    currentWord.toCharArray()) {

                totalWeight +=
                        letterWeights[
                                currentCharacter - 'a'
                        ];
            }

            // Reduce the weight to the range [0, 25]
            int mappedValue =
                    totalWeight % 26;

            // Convert the value into a character
            encodedResult.append(
                    (char) ('z' - mappedValue)
            );
        }

        return encodedResult.toString();
    }
}
