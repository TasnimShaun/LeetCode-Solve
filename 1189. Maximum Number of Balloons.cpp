class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char, int> freq;

        // Count each character
        for (char ch : text) {
            freq[ch]++;
        }

        // Find maximum number of "balloon"
        return min({
            freq['b'],
            freq['a'],
            freq['l'] / 2,
            freq['o'] / 2,
            freq['n']
        });
    }
};
