class Solution:
    def pivotArray(self,
                   numbers: List[int],
                   pivot_value: int) -> List[int]:

        # Elements smaller than the pivot
        smaller_elements = []

        # Elements equal to the pivot
        equal_elements = []

        # Elements greater than the pivot
        greater_elements = []

        for current_number in numbers:

            if current_number < pivot_value:
                smaller_elements.append(
                    current_number
                )

            elif current_number == pivot_value:
                equal_elements.append(
                    current_number
                )

            else:
                greater_elements.append(
                    current_number
                )

        # Combine all three groups
        return (
            smaller_elements +
            equal_elements +
            greater_elements
        )
