class Solution {
public:

    // Convert a Roman numeral character to its integer value
    int romanCharToValue(char romanChar) {
        switch (romanChar) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string romanString) {

        int decimalValue = 0;

        for (int index = 0; index < romanString.length(); index++) {

            // If current symbol is smaller than the next symbol,
            // subtract its value (e.g., IV = 4, IX = 9)
            if (index + 1 < romanString.length() &&
                romanCharToValue(romanString[index]) <
                romanCharToValue(romanString[index + 1])) {

                decimalValue -= romanCharToValue(romanString[index]);
            }
            else {
                // Otherwise, add the value normally
                decimalValue += romanCharToValue(romanString[index]);
            }
        }

        return decimalValue;
    }
};
