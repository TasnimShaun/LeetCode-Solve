/**
 * @param {number[]} gain
 * @return {number}
 */
var largestAltitude = function(gain) {
    // Current altitude of the biker
    let currentAlti = 0;
    
    // Highest altitude reached so far
    let maximumAlti = 0;
    
    // Traverse all altitude changes
    for (let change of gain) {
        // Update current altitude
        currentAlti += change;
        
        // Update maximum altitude if needed
        maximumAlti = Math.max(maximumAlti, currentAlti);
    }
    
    return maximumAlti;
};
