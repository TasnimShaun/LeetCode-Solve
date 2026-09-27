class Solution {
public:
    string reverseParentheses(string s) {
        int length = s.size();

        vector<int> matchingIndex(length);
        stack<int> openingBrackets;

        // Step 1: Find matching parentheses
        for (int index = 0; index < length; index++) {
            if (s[index] == '(') {
                openingBrackets.push(index);
            }
            else if (s[index] == ')') {
                int openingIndex = openingBrackets.top();
                openingBrackets.pop();

                matchingIndex[index] = openingIndex;
                matchingIndex[openingIndex] = index;
            }
        }

        // Step 2: Traverse the string
        string result;

        int index = 0;
        int direction = 1;

        while (index >= 0 && index < length) {
            if (s[index] == '(' || s[index] == ')') {
                index = matchingIndex[index];
                direction = -direction;
            }
            else {
                result += s[index];
            }

            index += direction;
        }

        return result;
    }
};
