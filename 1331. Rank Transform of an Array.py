class Solution:
    def arrayRankTransform(
        self,
        numbers: List[int]
    ) -> List[int]:

        # Create a sorted copy
        sorted_numbers = sorted(numbers)

        # Store rank of each unique number
        value_to_rank = {}

        current_rank = 1

        for value in sorted_numbers:

            if value not in value_to_rank:

                value_to_rank[value] = current_rank

                current_rank += 1

        # Replace each number with its rank
        return [
            value_to_rank[value]
            for value in numbers
        ]
