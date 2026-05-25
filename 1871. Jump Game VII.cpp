class Solution {
public:
    bool canReach(string binaryString, int minJump, int maxJump) {

        int length = binaryString.length();

        // Last position must be '0'
        if (binaryString.back() == '1')
            return false;

        // Mark starting position as visited
        binaryString[0] = 'v';

        // Number of reachable positions in the current sliding window
        int reachableCount = 0;

        // Farthest index that can currently be reached
        int farthestReachable = maxJump;

        for (int currentIndex = minJump; currentIndex < length; currentIndex++) {

            // If current index is beyond the farthest reachable position,
            // then no further progress is possible
            if (currentIndex > farthestReachable)
                return false;

            // Add the position entering the sliding window
            if (binaryString[currentIndex - minJump] == 'v')
                reachableCount++;

            // Remove the position leaving the sliding window
            if (currentIndex > maxJump &&
                binaryString[currentIndex - maxJump - 1] == 'v')
                reachableCount--;

            // If there exists a reachable position in the window
            // and the current cell is '0'
            if (reachableCount > 0 && binaryString[currentIndex] == '0') {

                // Mark current position as reachable
                binaryString[currentIndex] = 'v';

                // Update the farthest reachable index
                farthestReachable = currentIndex + maxJump;
            }
        }

        return reachableCount > 0;
    }
};
