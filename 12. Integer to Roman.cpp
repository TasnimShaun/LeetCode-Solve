class Solution {
public:
    string intToRoman(int number) {

        // Roman numeral values and their corresponding symbols
        const vector<pair<int, string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };

        string romanResult;

        // Traverse each value-symbol pair from largest to smallest
        for (const auto& [value, symbol] : romanMap) {

            // If number becomes 0, conversion is complete
            if (number == 0)
                break;

            // Keep adding the symbol while the number is large enough
            while (number >= value) {
                romanResult += symbol;
                number -= value;
            }
        }

        return romanResult;
    }
};
