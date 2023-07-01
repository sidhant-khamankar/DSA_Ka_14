/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // My solution O9^2 time O9^2 space
        // Like neetcode solution
        unordered_set<char> st;
        vector<unordered_set<char>> row_sets(board.size(), st);
        vector<unordered_set<char>> col_sets(board.size(), st);
        vector<unordered_set<char>> grid_sets(board.size(), st);

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] == '.')
                    continue;

                if (row_sets[i].find(board[i][j]) != row_sets[i].end())
                    return false;
                row_sets[i].insert(board[i][j]);

                if (col_sets[j].find(board[i][j]) != col_sets[j].end())
                    return false;
                col_sets[j].insert(board[i][j]);

                if (i <= 2)
                {
                    if (j <= 2)
                    {
                        if (grid_sets[0].find(board[i][j]) != grid_sets[0].end())
                            return false;
                        grid_sets[0].insert(board[i][j]);
                    }
                    else if (j <= 5)
                    {
                        if (grid_sets[1].find(board[i][j]) != grid_sets[1].end())
                            return false;
                        grid_sets[1].insert(board[i][j]);
                    }
                    else
                    {
                        if (grid_sets[2].find(board[i][j]) != grid_sets[2].end())
                            return false;
                        grid_sets[2].insert(board[i][j]);
                    }
                }
                else if (i <= 5)
                {
                    if (j <= 2)
                    {
                        if (grid_sets[3].find(board[i][j]) != grid_sets[3].end())
                            return false;
                        grid_sets[3].insert(board[i][j]);
                    }
                    else if (j <= 5)
                    {
                        if (grid_sets[4].find(board[i][j]) != grid_sets[4].end())
                            return false;
                        grid_sets[4].insert(board[i][j]);
                    }
                    else
                    {
                        if (grid_sets[5].find(board[i][j]) != grid_sets[5].end())
                            return false;
                        grid_sets[5].insert(board[i][j]);
                    }
                }
                else if (i <= 8)
                {
                    if (j <= 2)
                    {
                        if (grid_sets[6].find(board[i][j]) != grid_sets[6].end())
                            return false;
                        grid_sets[6].insert(board[i][j]);
                    }
                    else if (j <= 5)
                    {
                        if (grid_sets[7].find(board[i][j]) != grid_sets[7].end())
                            return false;
                        grid_sets[7].insert(board[i][j]);
                    }
                    else
                    {
                        if (grid_sets[8].find(board[i][j]) != grid_sets[8].end())
                            return false;
                        grid_sets[8].insert(board[i][j]);
                    }
                }
            }
        }

        return true;
    }
};
// @lc code=end
