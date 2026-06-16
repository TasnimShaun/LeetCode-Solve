class Solution {
public:

    string processStr(string inputString) {

        // Stores the final processed string
        string processedString;

        for (char currentCharacter : inputString) {

            // If it is a lowercase letter,
            // append it to the result
            if (currentCharacter >= 'a' &&
                currentCharacter <= 'z') {

                processedString.push_back(
                    currentCharacter
                );
            }

            // Remove the last character
            else if (currentCharacter == '*') {

                if (!processedString.empty()) {

                    processedString.pop_back();
                }
            }

            // Duplicate the current string
            else if (currentCharacter == '#') {

                processedString +=
                    processedString;
            }

            // Reverse the current string
            else if (currentCharacter == '%') {

                reverse(
                    processedString.begin(),
                    processedString.end()
                );
            }
        }

        return processedString;
    }
};
