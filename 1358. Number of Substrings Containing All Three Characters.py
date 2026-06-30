class Solution:
    def numberOfSubstrings(
        self,
        text: str
    ) -> int:

        total_substrings = 0

        string_length = len(text)

        # Latest positions of a, b, and c
        last_a_index = -1
        last_b_index = -1
        last_c_index = -1

        for current_index in range(
            string_length
        ):

            if text[current_index] == 'a':

                last_a_index = (
                    current_index
                )

            elif text[current_index] == 'b':

                last_b_index = (
                    current_index
                )

            elif text[current_index] == 'c':

                last_c_index = (
                    current_index
                )

            # Count valid substrings ending
            # at current_index
            total_substrings += (
                min(
                    last_a_index,
                    last_b_index,
                    last_c_index
                ) + 1
            )

        return total_substrings
