class Solution {
public:
    static const int MOD = 1000000007;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B, int sz) {
        Matrix C(sz, vector<long long>(sz, 0));

        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (A[i][k] == 0) continue;

                long long cur = A[i][k];

                for (int j = 0; j < sz; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + cur * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;

        Matrix T(sz, vector<long long>(sz, 0));

        for (int x = 0; x < m; x++) {

            for (int y = x + 1; y < m; y++) {
                T[x][m + y] = 1;
            }

            for (int y = 0; y < x; y++) {
                T[m + x][y] = 1;
            }
        }

        Matrix result(sz, vector<long long>(sz, 0));

        for (int i = 0; i < sz; i++) {
            result[i][i] = 1;
        }

        long long power = n - 1;

        while (power) {
            if (power & 1) {
                result = multiply(result, T, sz);
            }

            T = multiply(T, T, sz);
            power >>= 1;
        }

        long long answer = 0;

        for (int i = 0; i < sz; i++) {
            long long rowSum = 0;

            for (int j = 0; j < sz; j++) {
                rowSum = (rowSum + result[i][j]) % MOD;
            }

            answer = (answer + rowSum) % MOD;
        }

        return (int)answer;
    }
};
