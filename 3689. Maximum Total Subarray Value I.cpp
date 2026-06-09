class Solution {
public:
    long long maxTotalValue(vector<int>& A, int k) {

        // প্রথম element-কে initial minimum এবং maximum ধরা হচ্ছে
        int gMin = A.front();
        int gMax = A.front();

        // পুরো array traverse করে global minimum এবং maximum বের করছি
        for (auto& n : A) {

            // minimum update
            gMin = min(gMin, n);

            // maximum update
            gMax = max(gMax, n);
        }

        // সর্বোচ্চ possible subarray value = global max - global min
        // একই subarray k বার choose করা যায়,
        // তাই answer = (gMax - gMin) * k
        return (long long)(gMax - gMin) * k;
    }
};
