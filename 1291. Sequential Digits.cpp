class Solution {
public:
    vector<int> sequentialDigits(
        int low,
        int high
    ) {

        // All possible sequential digits
        string digitString = "123456789";

        vector<int> result;

        int minimumLength =
            to_string(low).size();

        int maximumLength =
            to_string(high).size();

        // Try every possible length
        for (int length = minimumLength;
             length <= maximumLength;
             length++) {

            // Generate sequential numbers
            for (int startIndex = 0;
                 startIndex + length <= 9;
                 startIndex++) {

                int number = stoi(
                    digitString.substr(
                        startIndex,
                        length
                    )
                );

                if (number >= low &&
                    number <= high) {

                    result.push_back(number);
                }
            }
        }

        return result;
    }
};
