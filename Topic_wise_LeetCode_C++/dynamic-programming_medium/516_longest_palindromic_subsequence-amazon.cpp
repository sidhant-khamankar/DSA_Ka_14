/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution
{
public:
    //Aditya verma gfg solution On^2 time On^2 space
    // A utility function to get max of two integers
    // int max(int x, int y) { return (x > y) ? x : y; }

    // // Returns the length of the longest palindromic subsequence in seq
    // int lps(char *seq, int i, int j)
    // {
    //     // Base Case 1: If there is only 1 character
    //     if (i == j)
    //         return 1;

    //     // Base Case 2: If there are only 2
    //     // characters and both are same
    //     if (seq[i] == seq[j] && i + 1 == j)
    //         return 2;

    //     // If the first and last characters match
    //     if (seq[i] == seq[j])
    //         return lps(seq, i + 1, j - 1) + 2;

    //     // If the first and last characters do not match
    //     return max(lps(seq, i, j - 1), lps(seq, i + 1, j));
    // }

    //dp solution
    // A utility function to get max of two integers
    int max(int x, int y) { return (x > y) ? x : y; }

    // Returns the length of the longest palindromic subsequence in seq
    int lps(char *str)
    {
        int n = strlen(str);
        int i, j, cl;
        int L[n][n]; // Create a table to store results of subproblems

        // Strings of length 1 are palindrome of lentgh 1
        for (i = 0; i < n; i++)
            L[i][i] = 1;

        // Build the table. Note that the lower diagonal values of table are
        // useless and not filled in the process. The values are filled in a
        // manner similar to Matrix Chain Multiplication DP solution (See
        // https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/). cl is length of
        // substring
        for (cl = 2; cl <= n; cl++)
        {
            for (i = 0; i < n - cl + 1; i++)
            {
                j = i + cl - 1;
                if (str[i] == str[j] && cl == 2)
                    L[i][j] = 2;
                else if (str[i] == str[j])
                    L[i][j] = L[i + 1][j - 1] + 2;
                else
                    L[i][j] = max(L[i][j - 1], L[i + 1][j]);
            }
        }

        return L[0][n - 1];
    }

    int longestPalindromeSubseq(string str)
    {
        int n = str.size();
        int i, j, cl;
        int L[n][n]; // Create a table to store results of subproblems

        // Strings of length 1 are palindrome of lentgh 1
        for (i = 0; i < n; i++)
            L[i][i] = 1;

        // Build the table. Note that the lower diagonal values of table are
        // useless and not filled in the process. The values are filled in a
        // manner similar to Matrix Chain Multiplication DP solution (See
        // https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/). cl is length of
        // substring
        for (cl = 2; cl <= n; cl++)
        {
            for (i = 0; i < n - cl + 1; i++)
            {
                j = i + cl - 1;
                if (str[i] == str[j] && cl == 2)
                    L[i][j] = 2;
                else if (str[i] == str[j])
                    L[i][j] = L[i + 1][j - 1] + 2;
                else
                    L[i][j] = max(L[i][j - 1], L[i + 1][j]);
            }
        }

        return L[0][n - 1];
    }
};
// @lc code=end
