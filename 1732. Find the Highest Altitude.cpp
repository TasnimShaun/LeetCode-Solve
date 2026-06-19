class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        // Current altitude of the biker
        int current_alti = 0;

        // Highest altitude reached so far
        int maximum_alti = 0;

        // Traverse all altitude changes
        for (int change : gain)
        {
            // Update current altitude
            current_alti += change;

            // Update maximum altitude if needed
            maximum_alti = max(maximum_alti, current_alti);
        }

        return maximum_alti;
    }
};
