/**
 * @param {number} currentHour
 * @param {number} currentMinute
 * @return {number}
 */
var angleClock = function(
    currentHour,
    currentMinute
) {

    // Convert 12 to 0 for easier calculation
    currentHour %= 12;

    // Minute hand moves 6 degrees per minute
    const minuteHandAngle =
        currentMinute * 6;

    // Hour hand moves 30 degrees per hour
    // and 0.5 degrees per minute
    const hourHandAngle =
        currentHour * 30 +
        currentMinute * 0.5;

    // Absolute difference between the angles
    const angleDifference =
        Math.abs(
            hourHandAngle -
            minuteHandAngle
        );

    // Return the smaller angle
    return Math.min(
        angleDifference,
        360 - angleDifference
    );
};
