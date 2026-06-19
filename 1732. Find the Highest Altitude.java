class Solution {
    public int largestAltitude(int[] gain) {
        // Current altitude of the biker
        int currentAlti = 0;
        
        // Highest altitude reached so far
        int maximumAlti = 0;
        
        // Traverse all altitude changes
        for (int change : gain) {
            // Update current altitude
            currentAlti += change;
            
            // Update maximum altitude if needed
            maximumAlti = Math.max(maximumAlti, currentAlti);
        }
        
        return maximumAlti;
    }
}
