class Solution {
    public int maxIceCream(int[] costs, int coins) {

        // Find maximum cost
        int xMin = Arrays.stream(costs).max().getAsInt();
        int xMax = xMin;

        // Frequency array
        int[] freq = new int[xMax + 1];

        for (int cost : costs) {

            // Count occurrences of each cost
            freq[cost]++;

            // Find minimum cost
            xMin = Math.min(xMin, cost);
        }

        int count = 0;

        // Buy ice creams from cheapest to most expensive
        for (int cost = xMin; cost <= xMax; cost++) {

            if (freq[cost] == 0) {
                continue;
            }

            // Maximum ice creams of this cost that can be bought
            int buy = Math.min(coins / cost, freq[cost]);

            if (buy == 0) {
                break;
            }

            count += buy;

            // Deduct spent coins
            coins -= buy * cost;
        }

        return count;
    }
}
