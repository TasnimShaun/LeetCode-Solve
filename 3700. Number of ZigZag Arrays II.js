/**
 * @param {number} n
 * @param {number} l
 * @param {number} r
 * @return {number}
 */
var zigZagArrays = function(n, l, r) {
    const MOD = 1000000007n;

    const m = r - l + 1;
    const sz = 2 * m;

    function multiply(A, B) {
        const C = Array.from(
            { length: sz },
            () => Array(sz).fill(0n)
        );

        for (let i = 0; i < sz; i++) {
            for (let k = 0; k < sz; k++) {

                const cur = A[i][k];
                if (cur === 0n) continue;

                for (let j = 0; j < sz; j++) {

                    const nxt = B[k][j];
                    if (nxt === 0n) continue;

                    C[i][j] = (C[i][j] + cur * nxt) % MOD;
                }
            }
        }

        return C;
    }

    let T = Array.from(
        { length: sz },
        () => Array(sz).fill(0n)
    );

    for (let x = 0; x < m; x++) {

        // Down -> Up
        for (let y = x + 1; y < m; y++) {
            T[x][m + y] = 1n;
        }

        // Up -> Down
        for (let y = 0; y < x; y++) {
            T[m + x][y] = 1n;
        }
    }

    let result = Array.from(
        { length: sz },
        (_, i) =>
            Array.from(
                { length: sz },
                (_, j) => (i === j ? 1n : 0n)
            )
    );

    let power = BigInt(n - 1);

    while (power > 0n) {

        if ((power & 1n) !== 0n) {
            result = multiply(result, T);
        }

        T = multiply(T, T);
        power >>= 1n;
    }

    let answer = 0n;

    for (let i = 0; i < sz; i++) {
        for (let j = 0; j < sz; j++) {
            answer = (answer + result[i][j]) % MOD;
        }
    }

    return Number(answer);
};
