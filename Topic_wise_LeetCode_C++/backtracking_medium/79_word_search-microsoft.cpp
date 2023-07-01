/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start

class Solution
{
    // My solution TLE 46/84 Tcs
    // Neetcode solution Om*n*4^n time as 4 calls in direction
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, 0, i, j, m, n))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>> &board, string word,
             int index, int i, int j, int m, int n)
    {

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index])
        {
            return false;
        }
        if (index == word.size() - 1)
        {
            return true;
        }

        board[i][j] = '#';

        if (dfs(board, word, index + 1, i - 1, j, m, n) || dfs(board, word, index + 1, i + 1, j, m, n) || dfs(board, word, index + 1, i, j - 1, m, n) || dfs(board, word, index + 1, i, j + 1, m, n))
        {
            return true;
        }

        board[i][j] = word[index];
        return false;
    }
};

// @lc code=end
