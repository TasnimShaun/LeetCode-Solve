class Solution:
    def countMajoritySubarrays(
        self,
        numbers: List[int],
        target_value: int
    ) -> int:

        array_size = len(numbers)

        # Stores frequency of balance values
        balance_frequency = [0] * (
            2 * array_size + 1
        )

        # Initial balance = 0
        balance_frequency[array_size] = 1

        current_balance = array_size

        valid_prefix_count = 0

        majority_subarray_count = 0

        for current_number in numbers:

            if current_number == target_value:

                # Count prefixes with same balance
                valid_prefix_count += (
                    balance_frequency[
                        current_balance
                    ]
                )

                current_balance += 1

                balance_frequency[
                    current_balance
                ] += 1

            else:

                current_balance -= 1

                valid_prefix_count -= (
                    balance_frequency[
                        current_balance
                    ]
                )

                balance_frequency[
                    current_balance
                ] += 1

            majority_subarray_count += (
                valid_prefix_count
            )

        return majority_subarray_count
