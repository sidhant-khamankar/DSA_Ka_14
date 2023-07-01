/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution
{
public:
    // did not get
    // neetcode solution On time On space top down with memoization
    int numDecodings(string s)
    {
        vector<int> dp(s.size(), -1);
        return numDecodings(s, 0, dp);
    }

    int numDecodings(string s, int i, vector<int> &dp)
    {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int count = 0;
        count += numDecodings(s, i + 1, dp);                                    // single character taken
        if (i < s.size() - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) // taking double characters
        {
            count += numDecodings(s, i + 2, dp);
        }
        dp[i] = count;
        return dp[i];
    }
};
// @lc code=end
