// ***
//
// You are given coins of different denominations and a total amount of money amount.
// Write a function to compute the fewest number of coins that you need to make up that amount.
// If that amount of money cannot be made up by any combination of the coins, return -1.
//
// Example 1:
// Input: coins = [1, 2, 5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
//
// Example 2:
// Input: coins = [2], amount = 3
// Output: -1
// Note:
//
// You may assume that you have an infinite number of each kind of coin.
//
// ***

// dp[i]: fewest number of coins that make up i amount of money.
//
// Why set all initial values in dp to amount + 1?
// Because max number of coins to make changes for money amount n should not be greater than n.
// You can't set initial values to INT_MAX because you might end up + 1 to it which result in overflow.
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

// Recursive.
// Postorder traversal of n-tree.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0) {
            return -1;
        }

        if (_memo.count(amount)) {
            return _memo[amount];
        }

        int minCoins = INT_MAX;
        for (int coin : coins) {
            int subproblem = coinChange(coins, amount - coin);

            // (amount - coin) cannot be made up by any combination of the coins, subproblem has no solution. Continue.
            if (subproblem == -1) {
                continue;
            }

            minCoins = min(minCoins, subproblem + 1);
        }

        return _memo[amount] = minCoins == INT_MAX ? -1 : minCoins;
    }

private:
    unordered_map<int, int> _memo = {{0, 0}};
};
