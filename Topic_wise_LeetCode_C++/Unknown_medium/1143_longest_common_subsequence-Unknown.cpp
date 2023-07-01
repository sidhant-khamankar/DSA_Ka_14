/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start

class Solution
{
public:
    // My solution passed all TCs but TLE time consumed
    // Memoization
    // int recur(string text1, string text2, int ind1, int ind2, vector<vector<int>> &dp)
    // {
    //     if (ind1 >= text1.size() || ind2 >= text2.size())
    //         return 0;
    //     else if (text1[ind1] == text2[ind2])
    //     {
    //         if (dp[ind1][ind2] == -1)
    //             dp[ind1][ind2] = 1 + recur(text1, text2, ind1 + 1, ind2 + 1, dp);

    //         return dp[ind1][ind2];
    //     }
    //     else if (text1[ind1] != text2[ind2])
    //     {
    //         if (dp[ind1][ind2] == -1)
    //             dp[ind1][ind2] = max(recur(text1, text2, ind1 + 1, ind2, dp), recur(text1, text2, ind1, ind2 + 1, dp));
    //         return dp[ind1][ind2];
    //     }

    //     return 0;
    // }

    // int longestCommonSubsequence(string text1, string text2)
    // {
    // int maxi = max(text1.size(), text2.size());
    // vector<vector<int>> dp(maxi, vector<int>(maxi, -1));
    // return recur(text1, text2, 0, 0, dp);
    // }

    // Aditya verma gfg solution Omn time
    // top down approach without using recursion stack space
    /* Returns length of LCS for X[0..m-1], Y[0..n-1] */
    int lcs(string X, string Y, int m, int n)
    {
        int L[m + 1][n + 1];
        int i, j;

        /* Following steps build L[m+1][n+1] in 
       bottom up fashion. Note that L[i][j] 
       contains length of LCS of X[0..i-1]
       and Y[0..j-1] */
        for (i = 0; i <= m; i++)
        {
            for (j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    L[i][j] = 0;

                else if (X[i - 1] == Y[j - 1])
                    L[i][j] = L[i - 1][j - 1] + 1;

                else
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }

        /* L[m][n] contains length of LCS 
    for X[0..n-1] and Y[0..m-1] */
        return L[m][n];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        return lcs(text1, text2, text1.size(), text2.size());
    }
};
// @lc code=end
