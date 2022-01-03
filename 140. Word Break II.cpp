// ***
//
// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
// add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible
// sentences.
//
// Note:
//
// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.
//
// Example 1:
// Input:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// Output:
// [
//   "cats and dog",
//   "cat sand dog"
// ]
//
// Example 2:
// Input:
// s = "pineapplepenapple"
// wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
// Output:
// [
//   "pine apple pen apple",
//   "pineapple pen apple",
//   "pine applepen apple"
// ]
// Explanation: Note that you are allowed to reuse a dictionary word.
//
// Example 3:
// Input:
// s = "catsandog"
// wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output:
// []
//
// ***
//
// Recursive solution. Given s, you find all words s[0, word.size()) that is in the dictionary,
// then recursively add all sentences composed by s[word.size(), end).
//
// wordBreak(catasanddog)
// = {cats + wordBreak(anddog),
//    cat + wordBreak(sanddog)}
//
// wordBreak(anddog)
// = {and + wordBreak(dog)}
//
// wordBreak(dog)
// = {dog + wordBreak("")}
//
// wordBreak("")
// = {""}

// Compare to 139. Word Break, this question is looking for all such possible sequences.
// in 139. Word Break you just need to return true / false.
class Solution {
public:
    // Returns all sentences (in terms of vector<string>) that can be formed be string s.
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (_cache.count(s)) {
            return _cache[s];
        }

        // If s.empty() it indicates that there's nothing to the right of s,
        // meaning we are at the last word, no space is needed.
        if (s.empty()) {
            return {""};
        }

        vector<string> sentences;
        for (string& word : wordDict) {
            if (s.substr(0, word.size()) == word) {
                vector<string> remain = wordBreak(s.substr(word.size()), wordDict);

                for (string& sentence : remain) {
                    sentences.push_back(word + (sentence.empty() ? "" : " ") + sentence);
                }
            }
        }

        return _cache[s] = sentences;
    }

private:
    unordered_map<string, vector<string>> _cache;
};

