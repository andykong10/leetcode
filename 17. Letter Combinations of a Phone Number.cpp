// ***
//
// Given a string containing digits from 2-9 inclusive (telephone numbers),
// return all possible letter combinations that the number could represent.
//
// Example:
//
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
// Note:
//
// Although the above answer is in lexicographical order, your answer could be in any order you want.
//
// ***

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string current;
        vector<string> all;

        int startIndex = 0;

        _backtrack(digits, startIndex, current, all);

        return all;
    }

private:
    void _backtrack(string& digits, int startIndex, string& current, vector<string>& all) {
        // We check if !current.empty() simply to deal with the case when input digits = "",
        // we do not want to return {""}. You can move it to parent function letterCombinations if you wish.
        if (startIndex == digits.size() and !current.empty()) {
            all.push_back(current);
            return;
        }

        string letters = _dict[digits[startIndex] - '0'];

        for (int i = 0; i < letters.size(); ++i) {
            current.push_back(letters[i]);
            _backtrack(digits, startIndex + 1, current, all);
            current.pop_back();
        }
    }

    vector<string> _dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};
