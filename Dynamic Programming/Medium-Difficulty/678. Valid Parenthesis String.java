/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true

Example 4:
Input: s = "("
Output: false
*/
class Solution {
    public boolean checkValidString(String s) {

     int first = 0, last = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                first++;
                last++;
            } else if (c == ')') {
                first--;
                last--;
            } else {
                first--;
                last++;
            }
            if (last < 0)
             return false;
            if (first < 0)
             first = 0;
        }
        return first == 0;   
    }
}
