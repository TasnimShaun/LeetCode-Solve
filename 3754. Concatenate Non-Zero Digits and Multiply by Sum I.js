/**
 * @param {number} number
 * @return {number}
 */
var sumAndMultiply = function(number) {

    let newNumber = 0;

    let digitSum = 0;

    // Find the highest place value
    let placeValue = 1;

    while (Math.floor(number / placeValue) >= 10) {
        placeValue *= 10;
    }

    // Process digits from left to right
    while (placeValue > 0) {

        const currentDigit = Math.floor(
            number / placeValue
        );

        number %= placeValue;

        if (currentDigit !== 0) {

            newNumber =
                newNumber * 10 +
                currentDigit;

            digitSum += currentDigit;
        }

        placeValue = Math.floor(
            placeValue / 10
        );
    }

    return newNumber * digitSum;
};
