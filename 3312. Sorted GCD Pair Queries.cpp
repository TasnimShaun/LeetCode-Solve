class Solution {
public:
    using ll = long long;

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int maxValue = *max_element(nums.begin(), nums.end());

        vector<int> frequency(maxValue + 1, 0);
        for (int x : nums) {
            frequency[x]++;
        }

        // exactPairs[g] = number of pairs whose gcd is exactly g
        vector<ll> exactPairs(maxValue + 1, 0);

        for (int g = maxValue; g >= 1; g--) {

            ll total = 0;

            for (int multiple = g; multiple <= maxValue; multiple += g) {
                total += frequency[multiple];
            }

            exactPairs[g] = total * (total - 1) / 2;

            for (int multiple = g * 2; multiple <= maxValue; multiple += g) {
                exactPairs[g] -= exactPairs[multiple];
            }
        }

        // prefix[g] = number of pairs with gcd <= g
        vector<ll> prefix(maxValue + 1, 0);

        for (int g = 1; g <= maxValue; g++) {
            prefix[g] = prefix[g - 1] + exactPairs[g];
        }

        vector<int> answer;

        for (long long q : queries) {

            int gcdValue = upper_bound(
                prefix.begin(),
                prefix.end(),
                q
            ) - prefix.begin();

            answer.push_back(gcdValue);
        }

        return answer;
    }
};
