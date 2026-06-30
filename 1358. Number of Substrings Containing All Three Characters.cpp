class Solution {
public:
    int numberOfSubstrings(string text) {

        int totalSubstrings = 0;

        int stringLength = text.size();

        // Latest positions of 'a', 'b', and 'c'
        int lastAIndex = -1;
        int lastBIndex = -1;
        int lastCIndex = -1;

        for (int currentIndex = 0;
             currentIndex < stringLength;
             currentIndex++) {

            if (text[currentIndex] == 'a') {

                lastAIndex = currentIndex;
            }
            else if (text[currentIndex] == 'b') {

                lastBIndex = currentIndex;
            }
            else if (text[currentIndex] == 'c') {

                lastCIndex = currentIndex;
            }

            // Count valid substrings ending
            // at the current index
            totalSubstrings +=
                min({
                    lastAIndex,
                    lastBIndex,
                    lastCIndex
                }) + 1;
        }

        return totalSubstrings;
    }
};
