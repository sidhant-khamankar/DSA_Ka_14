/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution
{
public:
    // My solution, code explainer solution dp On^2 time On^2 space
    int recur(int r, int c, vector<vector<int>> &matrix, int &R, int &C, vector<vector<int>> &dp)
    {

        if (dp[r][c] != -1)
        {
            return dp[r][c];
        }
        vector<int> rows = {1, 0, -1, 0};
        vector<int> cols = {0, 1, 0, -1};

        int max_len = 1;

        for (int i = 0; i < 4; i++)
        {
            if (r + rows[i] >= 0 && r + rows[i] < R && c + cols[i] >= 0 && c + cols[i] < C && matrix[r + rows[i]][c + cols[i]] > matrix[r][c])
            {
                max_len = max(max_len, 1 + recur(r + rows[i], c + cols[i], matrix, R, C, dp));
            }
        }

        return dp[r][c] = max_len;
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int R = matrix.size();
        int C = matrix[0].size();
        int maxi = 0;

        vector<vector<int>> dp(R + 1, vector<int>(C + 1, -1));

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                maxi = max(maxi, recur(i, j, matrix, R, C, dp));
            }
        }
        return maxi;
    }
};
// @lc code=end
