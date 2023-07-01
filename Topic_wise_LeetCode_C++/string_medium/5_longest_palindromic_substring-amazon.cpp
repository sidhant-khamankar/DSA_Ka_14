/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
// gfg tech dose solution On^2 time O^2 space
class Solution
{
public:
    // This function prints the
    // longest palindrome substring
    // It also returns the length of
    // the longest palindrome
    string longestPalindrome(string s)
    {
        // get length of input string
        int n = s.size();

        // table[i][j] will be false if substring
        // str[i..j] is not palindrome.
        // Else table[i][j] will be true
        bool table[n][n];

        memset(table, 0, sizeof(table));

        // All substrings of length 1
        // are palindromes
        int maxLength = 1;

        for (int i = 0; i < n; ++i)
            table[i][i] = true;

        // check for sub-string of length 2.
        int start = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (s[i] == s[i + 1])
            {
                table[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check for lengths greater than 2.
        // k is length of substring
        for (int k = 3; k <= n; ++k)
        {
            // Fix the starting index
            for (int i = 0; i < n - k + 1; ++i)
            {
                // Get the ending index of substring from
                // starting index i and length k
                int j = i + k - 1;

                // checking for sub-string from ith index to
                // jth index iff str[i+1] to str[j-1] is a
                // palindrome
                if (table[i + 1][j - 1] && s[i] == s[j])
                {
                    table[i][j] = true;

                    if (k > maxLength)
                    {
                        start = i;
                        maxLength = k;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};
// @lc code=end
