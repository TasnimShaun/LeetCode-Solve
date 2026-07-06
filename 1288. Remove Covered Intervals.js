/**
 * @param {number[][]} intervals
 * @return {number}
 */
var removeCoveredIntervals = function(intervals) {

    intervals.sort((first, second) => {

        if (first[0] === second[0]) {
            return second[1] - first[1];
        }

        return first[0] - second[0];
    });

    let maxEnd = -1;

    let remaining = 0;

    for (const [start, end] of intervals) {

        if (end > maxEnd) {

            remaining++;

            maxEnd = end;
        }
    }

    return remaining;
};
