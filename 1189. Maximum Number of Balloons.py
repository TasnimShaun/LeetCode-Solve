class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:

        freq = {}

        # Count each character
        for ch in text:
            freq[ch] = freq.get(ch, 0) + 1

        # Find maximum number of "balloon"
        return min(
            freq.get('b', 0),
            freq.get('a', 0),
            freq.get('l', 0) // 2,
            freq.get('o', 0) // 2,
            freq.get('n', 0)
        )
