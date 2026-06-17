class Solution:
    def processStr(
        self,
        input_string: str,
        target_index: int
    ) -> str:

        string_length = len(input_string)

        # Stores the processed string length
        # after each operation
        processed_lengths = [0] * string_length

        current_length = 0

        # Forward pass
        for current_index in range(string_length):

            current_character = (
                input_string[current_index]
            )

            if 'a' <= current_character <= 'z':

                current_length += 1

            elif current_character == '*':

                if current_length > 0:
                    current_length -= 1

            elif current_character == '#':

                current_length *= 2

            elif current_character == '%':

                pass

            processed_lengths[current_index] = (
                current_length
            )

        if target_index >= current_length:
            return '.'

        # Backward pass
        for current_index in range(
            string_length - 1,
            -1,
            -1
        ):

            current_character = (
                input_string[current_index]
            )

            length_before_operation = (
                0 if current_index == 0
                else processed_lengths[
                    current_index - 1
                ]
            )

            if 'a' <= current_character <= 'z':

                if (
                    target_index ==
                    length_before_operation
                ):
                    return current_character

            elif current_character == '#':

                if length_before_operation > 0:

                    target_index %= (
                        length_before_operation
                    )

            elif current_character == '%':

                target_index = (
                    length_before_operation
                    - 1
                    - target_index
                )

        return '.'
