class Solution:
    def sumAndMultiply(
        self,
        number: int
    ) -> int:

        new_number = 0

        digit_sum = 0

        # Find the highest place value
        place_value = 1

        while number // place_value >= 10:
            place_value *= 10

        # Process digits from left to right
        while place_value > 0:

            current_digit = (
                number // place_value
            )

            number %= place_value

            # Ignore zeros
            if current_digit != 0:

                new_number = (
                    new_number * 10 +
                    current_digit
                )

                digit_sum += current_digit

            place_value //= 10

        return new_number * digit_sum
