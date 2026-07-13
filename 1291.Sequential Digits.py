class Solution:
    def sequentialDigits(
        self,
        low: int,
        high: int
    ) -> List[int]:

        digits = "123456789"

        result = []

        min_length = len(str(low))
        max_length = len(str(high))

        for length in range(
            min_length,
            max_length + 1
        ):

            for start in range(
                0,
                10 - length
            ):

                number = int(
                    digits[start:start + length]
                )

                if low <= number <= high:
                    result.append(number)

        return result
