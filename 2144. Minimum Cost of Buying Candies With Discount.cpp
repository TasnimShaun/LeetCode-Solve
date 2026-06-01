class Solution {
public:

    int minimumCost(vector<int>& candyCosts) {

        // Sort costs in descending order
        sort(candyCosts.begin(),
             candyCosts.end(),
             greater<int>());

        int minimumTotalCost = 0;

        for (int index = 0;
             index < candyCosts.size();
             index++) {

            // Every third candy is free
            if (index % 3 == 2)
                continue;

            minimumTotalCost += candyCosts[index];
        }

        return minimumTotalCost;
    }
};
