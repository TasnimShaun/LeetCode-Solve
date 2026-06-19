class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        # Current altitude of the biker
        current_alti = 0
        
        # Highest altitude reached so far
        maximum_alti = 0
        
        # Traverse all altitude changes
        for change in gain:
            # Update current altitude
            current_alti += change
            
            # Update maximum altitude if needed
            maximum_alti = max(maximum_alti, current_alti)
        
        return maximum_alti
