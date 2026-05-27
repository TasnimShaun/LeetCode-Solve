
class Solution {
public:
    int numberOfSpecialChars(string inputString) {

        // Stores the last occurrence index of each lowercase letter
        vector<int> lastLowercasePosition(26, -1);

        // Stores the first occurrence index of each uppercase letter
        vector<int> firstUppercasePosition(26, -1);

        // Stores letters that violate the special character condition
        unordered_set<int> invalidLetters;

        for (int currentIndex = 0; currentIndex < inputString.length(); currentIndex++) {

            char currentChar = inputString[currentIndex];

            // Lowercase letter
            if (currentChar >= 'a' && currentChar <= 'z') {

                int letterIndex = currentChar - 'a';

                // Update last occurrence of lowercase letter
                lastLowercasePosition[letterIndex] = currentIndex;

                // If uppercase already appeared before lowercase,
                // then this letter can never be special
                if (firstUppercasePosition[letterIndex] != -1) {
                    invalidLetters.insert(letterIndex);
                }
            }
            // Uppercase letter
            else {

                int letterIndex = currentChar - 'A';

                // Store only the first occurrence of uppercase letter
                if (firstUppercasePosition[letterIndex] == -1) {
                    firstUppercasePosition[letterIndex] = currentIndex;
                }
            }
        }

        int specialCharacterCount = 0;

        // Check all 26 letters
        for (int letterIndex = 0; letterIndex < 26; letterIndex++) {

            if (lastLowercasePosition[letterIndex] != -1 &&
                firstUppercasePosition[letterIndex] != -1 &&
                !invalidLetters.count(letterIndex)) {

                specialCharacterCount++;
            }
        }

        return specialCharacterCount;
    }
};
