class Solution {
public:

    double angleClock(
        int currentHour,
        int currentMinute
    ) {

        // Convert 12 to 0 for easier calculation
        currentHour %= 12;

        // Minute hand moves 6 degrees per minute
        double minuteHandAngle =
            currentMinute * 6.0;

        // Hour hand moves 30 degrees per hour
        // and 0.5 degrees per minute
        double hourHandAngle =
            currentHour * 30.0 +
            currentMinute * 0.5;

        // Absolute difference between the two angles
        double angleDifference =
            abs(
                hourHandAngle -
                minuteHandAngle
            );

        // Return the smaller angle
        return min(
            angleDifference,
            360.0 - angleDifference
        );
    }
};
