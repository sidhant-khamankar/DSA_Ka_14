/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */

// @lc code=start
class Solution
{
public:
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

    int minInsertions(string s)
    {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s.size() - longestCommonSubsequence(s, rev);
        // code here
    }
};
// @lc code=end
