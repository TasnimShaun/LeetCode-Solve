class Solution:
    def leftRightDifference(self, numbers: List[int]) -> List[int]:

        # Sum of all elements (initial right sum)
        remaining_right_sum = sum(numbers)

        # Sum of elements on the left side
        current_left_sum = 0

        # Result array
        differences = [0] * len(numbers)

        for index in range(len(numbers)):

            # Remove current element from right sum
            remaining_right_sum -= numbers[index]

            # Store absolute difference
            differences[index] = abs(
                current_left_sum - remaining_right_sum
            )

            # Add current element to left sum
            current_left_sum += numbers[index]

        return differences
