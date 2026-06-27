from collections import Counter

class Solution:
    def maximumLength(
        self,
        numbers: List[int]
    ) -> int:

        # Stores the frequency of each number
        frequency_map = Counter(numbers)

        maximum_sequence_length = 1

        # Handle the special case for number 1
        if 1 in frequency_map:

            one_count = frequency_map[1]

            # The final length must be odd
            maximum_sequence_length = max(
                maximum_sequence_length,
                one_count
                if one_count % 2 == 1
                else one_count - 1
            )

        # Try every unique number
        # as the starting value
        for starting_value in frequency_map:

            if starting_value == 1:
                continue

            current_value = starting_value

            current_length = 0

            while current_value in frequency_map:

                # Need at least two occurrences
                # to continue the chain
                if (
                    frequency_map[current_value]
                    >= 2
                ):

                    current_length += 2

                    current_value *= (
                        current_value
                    )

                else:

                    # Last occurrence
                    current_length += 1

                    break

            # Final answer must be odd
            if current_length % 2 == 0:

                current_length -= 1

            maximum_sequence_length = max(
                maximum_sequence_length,
                current_length
            )

        return maximum_sequence_length
