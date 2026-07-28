/*
Question: You are given a palindromic string s.
Return the lexicographically smallest palindromic permutation of s.

Example 1:
Input: s = "z"
Output: "z"

Explanation:
A string of only one character is already the lexicographically smallest palindrome.
Example 2:
Input: s = "babab"
Output: "abbba"
Explanation:
Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.
Example 3:
Input: s = "daccad"
Output: "acddca"
Explanation:
Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.
*/

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> frequency(26, 0);

        for (char c : s)
            frequency[c - 'a']++;

        string left_side = "";
        string middle = "";

        for (int i = 0; i < 26; i++) {
            left_side.append(frequency[i] / 2, char('a' + i));

            if (frequency[i] % 2)
                middle = char('a' + i);
        }
