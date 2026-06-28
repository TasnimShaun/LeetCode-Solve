class Solution:
    def maximumElementAfterDecrementingAndRearranging(
        self,
        numbers: List[int]
    ) -> int:

        # Sort the array in ascending order
        numbers.sort()

        # The first element must be 1
        numbers[0] = 1

        # Make sure the difference between
        # adjacent elements is at most 1
        for index in range(1, len(numbers)):

            numbers[index] = min(
                numbers[index],
                numbers[index - 1] + 1
            )

        # The last element is the maximum
        return numbers[-1]
