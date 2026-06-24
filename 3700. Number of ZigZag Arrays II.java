import java.util.*;

class Solution {

    static final int MOD = 1000000007;

    private long[][] multiply(long[][] A, long[][] B, int sz) {

        long[][] C = new long[sz][sz];

        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {

                if (A[i][k] == 0) continue;

                long cur = A[i][k];

                for (int j = 0; j < sz; j++) {

                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + cur * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    public int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;
        int sz = 2 * m;

        // Transition matrix
        long[][] T = new long[sz][sz];

        for (int x = 0; x < m; x++) {

            // Down -> Up
            for (int y = x + 1; y < m; y++) {
                T[x][m + y] = 1;
            }

            // Up -> Down
            for (int y = 0; y < x; y++) {
                T[m + x][y] = 1;
            }
        }

        // Identity matrix
        long[][] result = new long[sz][sz];

        for (int i = 0; i < sz; i++) {
            result[i][i] = 1;
        }

        int power = n - 1;

        // Binary exponentiation
        while (power > 0) {

            if ((power & 1) == 1) {
                result = multiply(result, T, sz);
            }

            T = multiply(T, T, sz);

            power >>= 1;
        }

        long answer = 0;

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                answer = (answer + result[i][j]) % MOD;
            }
        }

        return (int) answer;
    }
}
