class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int landEnd  = landStartTime[i]  + landDuration[i];
                int waterEnd = waterStartTime[j] + waterDuration[j];

                // Order 1: Land ride i → Water ride j
                int finishLandFirst = max(landEnd, waterStartTime[j]) + waterDuration[j];

                // Order 2: Water ride j → Land ride i
                int finishWaterFirst = max(waterEnd, landStartTime[i]) + landDuration[i];

                ans = min(ans, min(finishLandFirst, finishWaterFirst));
            }
        }

        return ans;
    }
};
