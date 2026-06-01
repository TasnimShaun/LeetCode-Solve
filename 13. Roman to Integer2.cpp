class Solution {
public:

    int romanToInt(string romanString) {

        int decimalValue = 0;

        // Mapping Roman symbols to their integer values
        unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        // Process all characters except the last one
        for (int index = 0;
             index < romanString.size() - 1;
             index++) {

            // If current value is smaller than the next value,
            // subtract it (e.g., IV, IX, XL, CM)
            if (romanValues[romanString[index]] <
                romanValues[romanString[index + 1]]) {

                decimalValue -=
                    romanValues[romanString[index]];
            }
            else {

                decimalValue +=
                    romanValues[romanString[index]];
            }
        }

        // Add the value of the last Roman symbol
        return decimalValue +
               romanValues[romanString[romanString.size() - 1]];
    }
};
