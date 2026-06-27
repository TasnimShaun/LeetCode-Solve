class Solution {
public:
    int maximumLength(vector<int>& numbers) {

        // Stores the frequency of each number
        unordered_map<long long, int> frequencyMap;

        for (int currentNumber : numbers) {
            frequencyMap[currentNumber]++;
        }

        int maximumSequenceLength = 1;

        // Handle the special case for number 1
        if (frequencyMap.count(1)) {

            int oneCount = frequencyMap[1];

            // The final length must be odd
            maximumSequenceLength = max(
                maximumSequenceLength,
                (oneCount % 2 == 1)
                ? oneCount
                : oneCount - 1
            );
        }

        // Try every unique number as the starting value
        for (auto &[startingValue, occurrenceCount] : frequencyMap) {

            if (startingValue == 1) {
                continue;
            }

            long long currentValue = startingValue;

            int currentLength = 0;

            while (frequencyMap.count(currentValue)) {

                // Need at least two occurrences
                // to continue the chain
                if (frequencyMap[currentValue] >= 2) {

                    currentLength += 2;

                    currentValue =
                        currentValue * currentValue;
                }
                else {

                    // Last occurrence
                    currentLength++;

                    break;
                }
            }

            // Answer must always be odd
            if (currentLength % 2 == 0) {

                currentLength--;
            }

            maximumSequenceLength = max(
                maximumSequenceLength,
                currentLength
            );
        }

        return maximumSequenceLength;
    }
};
