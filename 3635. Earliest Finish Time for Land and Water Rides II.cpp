class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();

        // Precompute finish times
        vector<int> landEnd(n), waterEnd(m);
        for (int i = 0; i < n; i++) landEnd[i]  = landStartTime[i]  + landDuration[i];
        for (int j = 0; j < m; j++) waterEnd[j] = waterStartTime[j] + waterDuration[j];

        int ans = INT_MAX;

        // ── Order 1: Land → Water ─────────────────────────────────────────────
        // For each water ride j (swept by open time), find the best land ride:
        //   finish = max(landEnd[i], waterStartTime[j]) + waterDuration[j]
        // If any land ride ends ≤ waterStartTime[j]  →  finish = waterStartTime[j] + waterDuration[j]
        // Otherwise pick the land ride with the smallest landEnd               →  finish = landEnd[i] + waterDuration[j]
        {
            vector<int> sortedLandEnd = landEnd;
            sort(sortedLandEnd.begin(), sortedLandEnd.end());

            // indices of water rides sorted by open time
            vector<int> waterOrder(m);
            iota(waterOrder.begin(), waterOrder.end(), 0);
            sort(waterOrder.begin(), waterOrder.end(),
                 [&](int a, int b){ return waterStartTime[a] < waterStartTime[b]; });

            int ptr = 0;
            bool haveEarly = false;   // at least one land ride finished before current water opens

            for (int j : waterOrder) {
                int wo = waterStartTime[j], wd = waterDuration[j];

                // absorb all land rides that finish at or before wo
                while (ptr < n && sortedLandEnd[ptr] <= wo) {
                    haveEarly = true;
                    ptr++;
                }
                // Case A: a land ride already finished → wait for water to open
                if (haveEarly)
                    ans = min(ans, wo + wd);

                // Case B: earliest remaining land finish is still after wo
                if (ptr < n)
                    ans = min(ans, sortedLandEnd[ptr] + wd);
            }
        }

        // ── Order 2: Water → Land ─────────────────────────────────────────────
        // Symmetric: sweep land rides by open time; accumulate water finish times
        {
            vector<int> sortedWaterEnd = waterEnd;
            sort(sortedWaterEnd.begin(), sortedWaterEnd.end());

            vector<int> landOrder(n);
            iota(landOrder.begin(), landOrder.end(), 0);
            sort(landOrder.begin(), landOrder.end(),
                 [&](int a, int b){ return landStartTime[a] < landStartTime[b]; });

            int ptr = 0;
            bool haveEarly = false;

            for (int i : landOrder) {
                int lo = landStartTime[i], ld = landDuration[i];

                while (ptr < m && sortedWaterEnd[ptr] <= lo) {
                    haveEarly = true;
                    ptr++;
                }
                if (haveEarly)
                    ans = min(ans, lo + ld);

                if (ptr < m)
                    ans = min(ans, sortedWaterEnd[ptr] + ld);
            }
        }

        return ans;
    }
};
