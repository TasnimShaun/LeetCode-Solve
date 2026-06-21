class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:

        # Find maximum cost
        x_min = x_max = max(costs)

        # Frequency array
        freq = [0] * (x_max + 1)

        for cost in costs:

            # Count occurrences of each cost
            freq[cost] += 1

            # Find minimum cost
            x_min = min(x_min, cost)

        count = 0

        # Buy ice creams from cheapest to most expensive
        for cost in range(x_min, x_max + 1):

            if freq[cost] == 0:
                continue

            # Maximum ice creams of this cost that can be bought
            buy = min(coins // cost, freq[cost])

            if buy == 0:
                break

            count += buy

            # Deduct spent coins
            coins -= buy * cost

        return count
