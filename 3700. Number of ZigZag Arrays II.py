class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        MOD = 1000000007

        # Total distinct values in [l, r]
        m = r - l + 1

        # State count:
        # 0...(m-1)     -> last move was DOWN
        # m...(2m-1)    -> last move was UP
        sz = 2 * m

        # Matrix multiplication
        def multiply(A, B):
            C = [[0] * sz for _ in range(sz)]

            for i in range(sz):
                for k in range(sz):
                    if A[i][k] == 0:
                        continue

                    cur = A[i][k]

                    for j in range(sz):
                        if B[k][j] == 0:
                            continue

                        C[i][j] = (C[i][j] + cur * B[k][j]) % MOD

            return C

        # Transition matrix
        T = [[0] * sz for _ in range(sz)]

        for x in range(m):

            # Down -> Up
            for y in range(x + 1, m):
                T[x][m + y] = 1

            # Up -> Down
            for y in range(x):
                T[m + x][y] = 1

        # Identity matrix
        result = [[0] * sz for _ in range(sz)]
        for i in range(sz):
            result[i][i] = 1

        power = n - 1

        # Fast matrix exponentiation
        while power:
            if power & 1:
                result = multiply(result, T)

            T = multiply(T, T)
            power >>= 1

        answer = 0

        # Sum all entries
        for i in range(sz):
            answer = (answer + sum(result[i])) % MOD

        return answer
