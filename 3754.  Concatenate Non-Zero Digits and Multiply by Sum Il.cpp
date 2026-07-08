class Solution {
public:
    vector<int> sumAndMultiply(
        string s,
        vector<vector<int>>& queries
    ) {

        const long long MOD = 1000000007LL;

        int n = s.size();

        // Count of non-zero digits up to each index
        vector<int> nonZeroPrefixCount(n + 1, 0);

        // Store only non-zero digits
        vector<int> nonZeroDigits;

        for (int i = 0; i < n; i++) {

            nonZeroPrefixCount[i + 1] =
                nonZeroPrefixCount[i];

            if (s[i] != '0') {

                nonZeroPrefixCount[i + 1]++;

                nonZeroDigits.push_back(
                    s[i] - '0'
                );
            }
        }

        int totalDigits = nonZeroDigits.size();

        // Prefix value of formed number
        vector<long long> prefixNumber(totalDigits + 1, 0);

        // Prefix sum of digits
        vector<long long> prefixDigitSum(totalDigits + 1, 0);

        // Powers of 10 for modulo calculation
        vector<long long> powerOfTen(totalDigits + 1, 1);

        for (int i = 0; i < totalDigits; i++) {

            prefixNumber[i + 1] =
                (prefixNumber[i] * 10 +
                 nonZeroDigits[i]) % MOD;

            prefixDigitSum[i + 1] =
                prefixDigitSum[i] +
                nonZeroDigits[i];

            powerOfTen[i + 1] =
                (powerOfTen[i] * 10) % MOD;
        }

        vector<int> result;

        result.reserve(queries.size());

        for (auto& query : queries) {

            int leftIndex = query[0];
            int rightIndex = query[1];

            // Find range in non-zero digit array
            int start =
                nonZeroPrefixCount[leftIndex];

            int end =
                nonZeroPrefixCount[rightIndex + 1];

            int length = end - start;


            // Extract number formed by digits in range
            long long number =
                (prefixNumber[end]
                -
                (prefixNumber[start] *
                 powerOfTen[length]) % MOD
                +
                MOD) % MOD;


            // Sum of digits in range
            long long digitSum =
                prefixDigitSum[end] -
                prefixDigitSum[start];


            result.push_back(
                (number * digitSum) % MOD
            );
        }

        return result;
    }
};
