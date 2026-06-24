/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {

    const freq = {};

    // Count frequency of each character
    for (const ch of s) {
        freq[ch] = (freq[ch] || 0) + 1;
    }

    // Find first unique character
    for (let i = 0; i < s.length; i++) {

        if (freq[s[i]] === 1) {
            return i;
        }
    }

    return -1;
};
