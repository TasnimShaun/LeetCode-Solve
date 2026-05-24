class Solution {
public:
    int findMaxPath(int currentIndex, vector<int>& heights, int maxDistance, vector<int>& memo) {

        if (memo[currentIndex] != -1)
            return memo[currentIndex];

        int maxJumpCount = 1;
        int size = heights.size();

        // Right side search
        for (int nextIndex = currentIndex + 1;
             nextIndex <= min(size - 1, currentIndex + maxDistance);
             nextIndex++) {

            if (heights[nextIndex] >= heights[currentIndex])
                break;

            maxJumpCount = max(maxJumpCount,
                               1 + findMaxPath(nextIndex, heights, maxDistance, memo));
        }

        // Left side search
        for (int nextIndex = currentIndex - 1;
             nextIndex >= max(0, currentIndex - maxDistance);
             nextIndex--) {

            if (heights[nextIndex] >= heights[currentIndex])
                break;

            maxJumpCount = max(maxJumpCount,
                               1 + findMaxPath(nextIndex, heights, maxDistance, memo));
        }

        return memo[currentIndex] = maxJumpCount;
    }

    int maxJumps(vector<int>& heights, int maxDistance) {

        int size = heights.size();

        vector<int> memo(size, -1);

        int answer = 1;

        for (int startIndex = 0; startIndex < size; startIndex++) {
            answer = max(answer,
                         findMaxPath(startIndex, heights, maxDistance, memo));
        }

        return answer;
    }
};
