// ***
//
// Given a string s and an array of integers cost where cost[i] is the cost of deleting the ith character in s.
//
// Return the minimum cost of deletions such that there are no two identical letters next to each other.
//
// Notice that you will delete the chosen characters at the same time, in other words, after deleting a character, the
// costs of deleting other characters will not change.
//
//
//
// Example 1:
//
// Input: s = "abaac", cost = [1,2,3,4,5]
// Output: 3
// Explanation: Delete the letter "a" with cost 3 to get "abac" (String without two identical letters next to each
// other). Example 2:
//
// Input: s = "abc", cost = [1,2,3]
// Output: 0
// Explanation: You don't need to delete any character because there are no identical letters next to each other.
// Example 3:
//
// Input: s = "aabaa", cost = [1,2,3,4,1]
// Output: 2
// Explanation: Delete the first and the last character, getting the string ("aba").
//
//
// Constraints:
//
// s.length == cost.length
// 1 <= s.length, cost.length <= 10^5
// 1 <= cost[i] <= 10^4
// s contains only lowercase English letters.
//
// ***


// Maintain the running sum and max cost for repeated letters.
// For a group of continuous same characters, we need to delete all the group but leave only one character.
// For each group of continuous same characters, we need cost = sum_cost(group) - max_cost(group)
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int res = 0, max_cost = 0, sum_cost = 0;

        for (int i = 0; i < s.size(); ++i) {

            // When we see non-repeating letter, wrap up and reset.
            if (i > 0 && s[i] != s[i - 1]) {
                res += sum_cost - max_cost;
                sum_cost = max_cost = 0;
            }
            sum_cost += cost[i];
            max_cost = max(max_cost, cost[i]);
        }

        res += sum_cost - max_cost;

        return res;
    }
};

// Same idea. Hold the character with the biggest cost in hand.
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int res = 0;

        int maxCost = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 and s[i - 1] != s[i]) {
                maxCost = 0;
            }

            res += min(maxCost, cost[i]);
            maxCost = max(maxCost, cost[i]);
        }

        return res;
    }
};
