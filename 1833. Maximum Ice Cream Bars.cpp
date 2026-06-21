class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        // Find maximum cost
        int xMin = *max_element(costs.begin(), costs.end());
        int xMax = xMin;

        // Frequency of each cost
        vector<int> freq(xMax + 1, 0);

        for (int x : costs) {

            freq[x]++;

            // Find minimum cost
            xMin = min(xMin, x);
        }

        int cnt = 0;

        // Buy ice creams from cheapest to most expensive
        for (int x = xMin; x <= xMax; x++) {

            int f = freq[x];

            if (f == 0) {
                continue;
            }

            // Maximum ice creams of cost x that can be bought
            int buy = min(coins / x, f);

            if (buy == 0) {
                break;
            }

            cnt += buy;

            // Deduct spent coins
            coins -= buy * x;
        }

        return cnt;
    }
};
