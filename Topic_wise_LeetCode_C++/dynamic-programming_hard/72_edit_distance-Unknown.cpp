/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution
{
public:
    //did not get
    // Striver solution
    // Bruteforce recursion O2^n time

    // dp Om*n time On*m space
    int editDist(int i, int j, string s1, string s2, vector<vector<int>> &dp)
    {
        if (i == s1.size())
            return s2.size() - j;

        if (j == s2.size())
            return s1.size() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
        {
            return dp[i][j] = editDist(i + 1, j + 1, s1, s2, dp);
        }

        else
        {                                                       // if both are not same;
            int left = 1 + editDist(i, j + 1, s1, s2, dp);      // insert
            int mid = 1 + editDist(i + 1, j, s1, s2, dp);       // remove
            int right = 1 + editDist(i + 1, j + 1, s1, s2, dp); // replace
            return dp[i][j] = min(left, min(mid, right));
        }
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return editDist(0, 0, word1, word2, dp);
    }
};
// @lc code=end
