class Solution:
    def mapWordWeights(
        self,
        word_list: List[str],
        letter_weights: List[int]
    ) -> str:

        encoded_characters = []

        # Process each word
        for current_word in word_list:

            total_weight = 0

            # Calculate the total weight of the word
            for current_character in current_word:

                total_weight += (
                    letter_weights[
                        ord(current_character) - ord('a')
                    ]
                )

            # Reduce the weight to the range [0, 25]
            mapped_value = total_weight % 26

            # Convert the value into a character
            encoded_characters.append(
                chr(ord('z') - mapped_value)
            )

        return "".join(encoded_characters)
