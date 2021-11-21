// ***
//
// Given two words (beginWord and endWord), and a dictionary's word list,
// find the length of shortest transformation sequence from beginWord to endWord, such that:
// - Only one letter can be changed at a time.
// - Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//
// Note:
// - Return 0 if there is no such transformation sequence.
// - All words have the same length.
// - All words contain only lowercase alphabetic characters.
// - You may assume no duplicates in the word list.
// - You may assume beginWord and endWord are non-empty and are not the same.
//
// Example 1:
//
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
//
// Output: 5
//
// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
//
// Example 2:
//
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
//
// Output: 0
//
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
//
// ***

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());

    if (not dict.count(endWord)) {
        return 0;
    }

    queue<string> q;
    q.push(beginWord);

    int level = 0;
    while (not q.empty()) {
        ++level;

        int qSize = q.size();
        while (qSize--) {
            string word = q.front();
            q.pop();

            // Found the solution
            if (word == endWord) {
                return level;
            }

            // For every letter in word
            for (int i = 0; i < word.size(); ++i) {
                char original_letter = word[i];

                // Replace that letter with 'a' thru 'z'.
                for (int c = 'a'; c <= 'z'; ++c) {
                    word[i] = c;

                    // If word exists in dict, push it to the queue for next bfs level.
                    if (dict.count(word)) {
                        // Remember to erase the word from dict (so you don't have to keep explicit visited array)
                        dict.erase(word);
                        q.push(word);
                    }
                }

                // Don't forget to revert word[i] back to original_letter!
                word[i] = original_letter;
            }
        }
    }

    return 0;
}
