class Solution {
public:

    string mapWordWeights(vector<string>& wordList,
                          vector<int>& letterWeights) {

        string encodedString;

        // Process each word
        for (const string& currentWord : wordList) {

            int totalWeight = 0;

            // Calculate the total weight of the current word
            for (char currentCharacter : currentWord) {

                totalWeight +=
                    letterWeights[currentCharacter - 'a'];
            }

            // Reduce the weight into the range [0, 25]
            int mappedValue = totalWeight % 26;

            // Convert the value into a character
            encodedString.push_back(
                char('z' - mappedValue)
            );
        }

        return encodedString;
    }
};
