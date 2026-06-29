/**
 * @param {string[]} patterns
 * @param {string} word
 * @return {number}
 */
var numOfStrings = function(patterns, word) {
    let answer = 0;

    for (const p of patterns) {

        if (word.includes(p)) {
            answer++;
        }
    }

    return answer;
};
