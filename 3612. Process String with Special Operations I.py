class Solution:
    def processStr(
        self,
        input_string: str
    ) -> str:

        # Using a list for efficient modifications
        processed_characters = []

        for current_character in input_string:

            # If it is a lowercase letter,
            # append it to the result
            if 'a' <= current_character <= 'z':

                processed_characters.append(
                    current_character
                )

            # Remove the last character
            elif current_character == '*':

                if processed_characters:

                    processed_characters.pop()

            # Duplicate the current string
            elif current_character == '#':

                processed_characters.extend(
                    processed_characters
                )

            # Reverse the current string
            elif current_character == '%':

                processed_characters.reverse()

        return "".join(processed_characters)
