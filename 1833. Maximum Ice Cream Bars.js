/**
 * @param {number[]} costs
 * @param {number} coins
 * @return {number}
 */
var maxIceCream = function(costs, coins) {

    // Find maximum cost
    let xMin = Math.max(...costs);
    let xMax = xMin;

    // Frequency array
    const freq = new Array(xMax + 1).fill(0);

    for (const cost of costs) {

        // Count occurrences of each cost
        freq[cost]++;

        // Find minimum cost
        xMin = Math.min(xMin, cost);
    }

    let count = 0;

    // Buy ice creams from cheapest to most expensive
    for (let cost = xMin; cost <= xMax; cost++) {

        if (freq[cost] === 0) {
            continue;
        }

        // Maximum ice creams of this cost that can be bought
        const buy = Math.min(Math.floor(coins / cost), freq[cost]);

        if (buy === 0) {
            break;
        }

        count += buy;

        // Deduct spent coins
        coins -= buy * cost;
    }

    return count;
};
