class Solution {
public:

    long long maxTotalValue(vector<int>& numbers,
                            int operationsCount) {

        int arraySize = numbers.size();

        // Precompute log values for Sparse Table
        vector<int> logTable(arraySize + 1);

        for (int length = 2;
             length <= arraySize;
             length++) {

            logTable[length] =
                logTable[length / 2] + 1;
        }

        int maxPower =
            logTable[arraySize] + 1;

        // Sparse Table for range maximum
        vector<vector<int>> maxSparseTable(
            maxPower,
            vector<int>(arraySize)
        );

        // Sparse Table for range minimum
        vector<vector<int>> minSparseTable(
            maxPower,
            vector<int>(arraySize)
        );

        // Base layer
        for (int index = 0;
             index < arraySize;
             index++) {

            maxSparseTable[0][index] =
                numbers[index];

            minSparseTable[0][index] =
                numbers[index];
        }

        // Build Sparse Tables
        for (int power = 1;
             power < maxPower;
             power++) {

            for (int startIndex = 0;
                 startIndex + (1 << power) <= arraySize;
                 startIndex++) {

                maxSparseTable[power][startIndex] =
                    max(
                        maxSparseTable[power - 1][startIndex],

                        maxSparseTable[power - 1]
                                      [startIndex +
                                       (1 << (power - 1))]
                    );

                minSparseTable[power][startIndex] =
                    min(
                        minSparseTable[power - 1][startIndex],

                        minSparseTable[power - 1]
                                      [startIndex +
                                       (1 << (power - 1))]
                    );
            }
        }

        // Returns:
        // max(subarray) - min(subarray)
        auto calculateValue =
            [&](int leftIndex,
                int rightIndex) -> long long {

            int segmentLength =
                rightIndex - leftIndex + 1;

            int power =
                logTable[segmentLength];

            int maximumValue =
                max(
                    maxSparseTable[power][leftIndex],

                    maxSparseTable[power]
                                  [rightIndex -
                                   (1 << power) + 1]
                );

            int minimumValue =
                min(
                    minSparseTable[power][leftIndex],

                    minSparseTable[power]
                                  [rightIndex -
                                   (1 << power) + 1]
                );

            return 1LL * maximumValue -
                   minimumValue;
        };

        struct SubarrayInfo {

            long long value;

            int leftIndex;

            int rightIndex;

            bool operator<(
                const SubarrayInfo& other
            ) const {

                return value < other.value;
            }
        };

        // Max Heap
        priority_queue<SubarrayInfo>
            maxHeap;

        // Initially consider all subarrays
        // [leftIndex ... n-1]
        for (int leftIndex = 0;
             leftIndex < arraySize;
             leftIndex++) {

            maxHeap.push({
                calculateValue(
                    leftIndex,
                    arraySize - 1
                ),
                leftIndex,
                arraySize - 1
            });
        }

        long long totalValue = 0;

        // Take the largest value k times
        while (operationsCount--) {

            SubarrayInfo currentBest =
                maxHeap.top();

            maxHeap.pop();

            totalValue +=
                currentBest.value;

            // Shrink subarray from the right
            if (currentBest.rightIndex >
                currentBest.leftIndex) {

                maxHeap.push({
                    calculateValue(
                        currentBest.leftIndex,
                        currentBest.rightIndex - 1
                    ),
                    currentBest.leftIndex,
                    currentBest.rightIndex - 1
                });
            }
        }

        return totalValue;
    }
};
