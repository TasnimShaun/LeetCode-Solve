class Solution {
public:

    static int numberOfSpecialChars(string& inputString) {

        // Stores presence of lowercase letters
        bitset<26> lowercaseLetters = 0;

        // Stores presence of uppercase letters
        bitset<26> uppercaseLetters = 0;

        for (char currentChar : inputString) {

            // If lowercase letter
            if (currentChar >= 'a') {
                lowercaseLetters[currentChar - 'a'] = 1;
            }
            // If uppercase letter
            else {
                uppercaseLetters[currentChar - 'A'] = 1;
            }
        }

        // Keep only letters that appear in both lowercase and uppercase
        bitset<26> specialLetters = lowercaseLetters & uppercaseLetters;

        // Count such letters
        return specialLetters.count();
    }
};
