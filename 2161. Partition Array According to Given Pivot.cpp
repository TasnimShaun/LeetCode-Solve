class Solution {
public:

    vector<int> pivotArray(vector<int>& numbers,
                           int pivotValue) {

        // Elements smaller than pivot
        vector<int> smallerElements;

        // Elements equal to pivot
        vector<int> equalElements;

        // Elements greater than pivot
        vector<int> greaterElements;

        for (int currentNumber : numbers) {

            if (currentNumber < pivotValue) {

                smallerElements.push_back(
                    currentNumber
                );
            }
            else if (currentNumber == pivotValue) {

                equalElements.push_back(
                    currentNumber
                );
            }
            else {

                greaterElements.push_back(
                    currentNumber
                );
            }
        }

        // Append all pivot elements
        smallerElements.insert(
            smallerElements.end(),
            equalElements.begin(),
            equalElements.end()
        );

        // Append all greater elements
        smallerElements.insert(
            smallerElements.end(),
            greaterElements.begin(),
            greaterElements.end()
        );

        return smallerElements;
    }
};
