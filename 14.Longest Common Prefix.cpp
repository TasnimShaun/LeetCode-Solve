class Solution {
public:

    string longestCommonPrefix(vector<string>& words) {

        string commonPrefix = "";

        // Sort strings lexicographically
        sort(words.begin(), words.end());

        int totalStrings = words.size();

        // After sorting, only first and last strings are needed
        string firstWord = words[0];
        string lastWord = words[totalStrings - 1];

        // Compare characters of first and last strings
        for (int position = 0;
             position < min(firstWord.size(), lastWord.size());
             position++) {

            // Mismatch found
            if (firstWord[position] != lastWord[position]) {
                return commonPrefix;
            }

            // Add matching character to prefix
            commonPrefix += firstWord[position];
        }

        return commonPrefix;
    }
};
