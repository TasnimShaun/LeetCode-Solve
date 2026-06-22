/**
 * @param {string} text
 * @return {number}
 */
var maxNumberOfBalloons = function(text) {

    const freq = {};

    // Count each character
    for (const ch of text) {
        freq[ch] = (freq[ch] || 0) + 1;
    }

    // Find maximum number of "balloon"
    return Math.min(
        freq['b'] || 0,
        freq['a'] || 0,
        Math.floor((freq['l'] || 0) / 2),
        Math.floor((freq['o'] || 0) / 2),
        freq['n'] || 0
    );
};
