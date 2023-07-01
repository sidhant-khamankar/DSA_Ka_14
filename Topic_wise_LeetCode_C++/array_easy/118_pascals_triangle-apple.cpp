/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        //On^2 time On^2 space
        vector<vector<int>> matrix{{1}, {1, 1}};
        if (numRows == 1)
            return {{1}};
        else if (numRows == 2)
            return matrix;
        else
        {
            for (int i = 2; i < numRows; i++)
            {
                vector<int> row;
                row.emplace_back(1);
                int first = 0;
                int second = 1;
                for (int j = 1; j < i; j++)
                {
                    row.emplace_back(matrix[i - 1][first] + matrix[i - 1][second]);
                    first++;
                    second++;
                }
                row.emplace_back(1);
                matrix.emplace_back(row);
            }
            return matrix;
        }
    }
};
// @lc code=end
