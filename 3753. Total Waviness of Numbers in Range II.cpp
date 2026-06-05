class Solution {
public:

    struct StateResult {

        // Number of valid numbers formed
        long long countNumbers;

        // Total waviness contributed by those numbers
        long long totalWaviness;
    };

    string numberString;

    StateResult memo[20][2][11][11];

    bool computed[20][2][11][11];

    StateResult digitDP(int position,
                        int hasStarted,
                        int lastDigit,
                        int secondLastDigit,
                        bool isTight) {

        // Reached end of number
        if (position == (int)numberString.size()) {
            return {1, 0};
        }

        // Use memoized result
        if (!isTight &&
            computed[position][hasStarted]
                    [lastDigit][secondLastDigit]) {

            return memo[position][hasStarted]
                       [lastDigit][secondLastDigit];
        }

        int digitLimit =
            isTight
                ? numberString[position] - '0'
                : 9;

        StateResult currentResult = {0, 0};

        for (int currentDigit = 0;
             currentDigit <= digitLimit;
             currentDigit++) {

            bool nextTight =
                isTight &&
                (currentDigit == digitLimit);

            // Still skipping leading zeros
            if (!hasStarted && currentDigit == 0) {

                StateResult nextState =
                    digitDP(position + 1,
                            0,
                            10,
                            10,
                            nextTight);

                currentResult.countNumbers +=
                    nextState.countNumbers;

                currentResult.totalWaviness +=
                    nextState.totalWaviness;
            }
            else {

                long long newWaveContribution = 0;

                // Check whether the middle digit forms a peak/valley
                if (hasStarted &&
                    secondLastDigit != 10) {

                    bool isPeak =
                        (lastDigit > secondLastDigit &&
                         lastDigit > currentDigit);

                    bool isValley =
                        (lastDigit < secondLastDigit &&
                         lastDigit < currentDigit);

                    if (isPeak || isValley) {
                        newWaveContribution = 1;
                    }
                }

                int nextSecondLastDigit =
                    hasStarted ? lastDigit : 10;

                int nextLastDigit =
                    currentDigit;

                StateResult nextState =
                    digitDP(position + 1,
                            1,
                            nextLastDigit,
                            nextSecondLastDigit,
                            nextTight);

                currentResult.countNumbers +=
                    nextState.countNumbers;

                currentResult.totalWaviness +=
                    nextState.totalWaviness +
                    newWaveContribution *
                    nextState.countNumbers;
            }
        }

        // Memoize non-tight states
        if (!isTight) {

            computed[position][hasStarted]
                    [lastDigit][secondLastDigit] = true;

            memo[position][hasStarted]
                [lastDigit][secondLastDigit] =
                currentResult;
        }

        return currentResult;
    }

    long long calculateWavinessUpTo(long long limit) {

        if (limit < 0)
            return 0;

        numberString = to_string(limit);

        memset(computed, 0, sizeof(computed));

        return digitDP(
                   0,
                   0,
                   10,
                   10,
                   true)
            .totalWaviness;
    }

    long long totalWaviness(long long leftBound,
                            long long rightBound) {

        return calculateWavinessUpTo(rightBound) -
               calculateWavinessUpTo(leftBound - 1);
    }
};
