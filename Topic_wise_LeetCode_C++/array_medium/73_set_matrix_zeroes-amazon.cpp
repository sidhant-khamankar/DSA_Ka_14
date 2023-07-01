/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // duplicate matrix Omn space
        // Om+n space Omn time
        set<int> rows;
        set<int> columns;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        for (auto row : rows)
        {
            for (int i = 0; i < matrix[0].size(); i++)
                matrix[row][i] = 0;
        }
        for (auto column : columns)
        {
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][column] = 0;
        }
    }
};
// @lc code=end
