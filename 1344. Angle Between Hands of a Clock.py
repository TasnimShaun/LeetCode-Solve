class Solution:
    def angleClock(
        self,
        current_hour: int,
        current_minute: int
    ) -> float:

        # Convert 12 to 0 for easier calculation
        current_hour %= 12

        # Minute hand moves 6 degrees per minute
        minute_hand_angle = (
            current_minute * 6.0
        )

        # Hour hand moves 30 degrees per hour
        # and 0.5 degrees per minute
        hour_hand_angle = (
            current_hour * 30.0 +
            current_minute * 0.5
        )

        # Absolute difference between the angles
        angle_difference = abs(
            hour_hand_angle -
            minute_hand_angle
        )

        # Return the smaller angle
        return min(
            angle_difference,
            360.0 - angle_difference
        )
