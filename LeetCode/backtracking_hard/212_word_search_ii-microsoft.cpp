/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start

// My solution - Buffer overflow
// Neetcode solution, Trie prefix tree data structure
// Bruteforce Words*mn*4^mn for all 4 directions for each character in whole matrix

/*
Given a board of characters & a list of words, return all words on the board
Implement trie, for search: iterate thru children until isWord, add to result
Time: O(m x (4 x 3^(l - 1))) -> m = # of cells, l = max length of words
Space: O(n) -> n = total number of letters in dictionary (no overlap in Trie)
*/
struct TrieNode
{
    TrieNode *children[26] = {};
    string *word;
    void addWord(string &word)
    {
        TrieNode *cur = this;
        for (char c : word)
        {
            c -= 'a';
            if (cur->children[c] == nullptr)
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->word = &word;
    }
};

class Solution
{
public:
    int m, n;
    int DIR[5] = {0, 1, 0, -1, 0};
    vector<string> ans;
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        m = board.size();
        n = board[0].size();
        TrieNode trieNode;
        for (string &word : words)
            trieNode.addWord(word);

        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                dfs(board, r, c, &trieNode);
        return ans;
    }
    void dfs(vector<vector<char>> &board, int r, int c, TrieNode *cur)
    {
        if (r < 0 || r == m || c < 0 || c == n || board[r][c] == '#' || cur->children[board[r][c] - 'a'] == nullptr)
            return;
        char orgChar = board[r][c];
        cur = cur->children[orgChar - 'a'];
        if (cur->word != nullptr)
        {
            ans.push_back(*cur->word);
            cur->word = nullptr; // Avoid duplication!
        }
        board[r][c] = '#'; // mark as visited!
        for (int i = 0; i < 4; ++i)
            dfs(board, r + DIR[i], c + DIR[i + 1], cur);
        board[r][c] = orgChar; // restore org state
    }
};
// @lc code=end
