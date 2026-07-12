class Solution {
public:
    vector<int> arrayRankTransform(
        vector<int>& numbers
    ) {

        // Copy and sort the array
        vector<int> sortedNumbers = numbers;

        sort(
            sortedNumbers.begin(),
            sortedNumbers.end()
        );

        // Remove duplicate values
        sortedNumbers.erase(
            unique(
                sortedNumbers.begin(),
                sortedNumbers.end()
            ),
            sortedNumbers.end()
        );

        // Replace each element with its rank
        for (int i = 0; i < numbers.size(); i++) {

            numbers[i] =
                lower_bound(
                    sortedNumbers.begin(),
                    sortedNumbers.end(),
                    numbers[i]
                ) - sortedNumbers.begin() + 1;
        }

        return numbers;
    }
};
