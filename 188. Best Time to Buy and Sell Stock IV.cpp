// ***
//
// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete at most k transactions.
//
// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//
// Example 1:
//
// Input: [2,4,1], k = 2
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
//
// Example 2:
//
// Input: [3,2,6,5,0,3], k = 2
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
//              Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//
// ***
//
//                         d/n                     d/n                     d/n                     d/n
// SOLD0 ---------------> HOLD1 ----------------> SOLD1 ----------------> HOLD2 ----------------> SOLD2 ... SOLDK
//         buy (-price)           sell (+price)           buy (-price)            sell (+price)

int maxProfit(int k, vector<int>& prices) {
    // Same as saying we can perform unlimited transaction, the situation becomes the same as
    // 122. Best Time to Buy and Sell Stock II, you just add all profit you can get.
    // Theoretically you don't have to check it, but then the vector you allocate to store
    // ith transaction will be too big.
    if (k >= prices.size() / 2) {
        int total = 0;

        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];

            if (diff > 0) {
                total += diff;
            }
        }

        return total;
    }

    // If you are limited by k transactions, this situation becomes a generalization of solution to
    // 123. Best Time to Buy and Sell Stock III, if you understand that question, then understanding this one is easy,
    // otherwise you will be confused.
    //
    // Why k+1? because you need sold[0] to update hold[1] = max(hold[1], sold[0] - prices[1]),
    // sold[0] will always be 0 and hold[0] will always be INT_MIN.
    // Note here the index i in hold/sold records the ith time you buy/sell.

    // Element i represents the max amount of money you could have in the state when you've sold the ith stock
    vector<int> sold(k + 1, 0);

    // Element i represents the max amount of money you could have in the state when you are holding the ith stock
    vector<int> hold(k + 1, INT_MIN);

    for (int i = 0; i < prices.size(); ++i) {
        for (int j = k; j > 0; --j) {
            // You can only sold the jth stock after you've bought the jth stock, that's why hold[j] + prices[i]
            sold[j] = max(sold[j], hold[j] + prices[i]);

            // You can only hold the jth stock after you've sold the j-1 th stock, that's why sold[j-1] - prices[i]
            hold[j] = max(hold[j], sold[j - 1] - prices[i]);
        }
    }

    return sold[k];
}
