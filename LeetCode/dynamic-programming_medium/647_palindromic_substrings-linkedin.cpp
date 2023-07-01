/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution
{
public:
    // Leetcode discuss, Neetcode solution, On^2 time O1 space
    // int countSubstrings(string s)
    // {
    //     if (s.length() == 0)
    //         return 0;
    //     int res = 0;
    //     for (int i = 0; i < s.length(); i++)
    //     {
    //         expandAroundCenter(s, i, i, res);
    //         expandAroundCenter(s, i, i + 1, res);
    //     }
    //     return res;
    // }

    // int expandAroundCenter(string s, int left, int right, int &res)
    // {
    //     if (s.length() == 0 || left > right)
    //         return 0;
    //     while (left >= 0 && right < s.length() && s[left] == s[right])
    //         left--, right++, res++;
    //     return res;
    // }

    // My solution On^3 time O1 space
    // Memoize isPlaindrome function dp[i][j] -> On^2 time
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                break;
            }
            i++;
            j--;
        }

        if (s[i] == s[j])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int countSubstrings(string s)
    {

        int ans = 0;

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (isPalindrome(s.substr(i, j - i + 1)))
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};
// @lc code=end
