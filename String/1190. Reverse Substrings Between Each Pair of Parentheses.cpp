/*
You are given a string s that consists of lower case English letters and brackets.
Reverse the strings in each pair of matching parentheses, starting from the innermost one.
Your result should not contain any brackets.
Example 1:
Input: s = "(abcd)"
Output: "dcba"

Example 2:
Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

Example 3:
Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
*/

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
