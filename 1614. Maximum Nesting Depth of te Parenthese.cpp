class Solution {
public:
    int maxDepth(string str) {
        int depth = 0, maxDepth = 0;
        for (char character  : str)    
         {
            if (character == '(') {
                depth++;
                if (depth > maxDepth) maxDepth = depth;
            } else if (character  == ')') {
                depth--;
            }
        }
        return maxDepth;
    }
};
