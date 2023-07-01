/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
// My solution On time O1 space
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        if (n == 1)
            return strs[0];
        string ans;
        char c = strs[0][0];
        int k = 0;
        for (int i = 1; i < n; i++)
        {
            if (k >= strs[i].size() || strs[i][k] != c)
            {
                return ans;
            }
            else if (i == n - 1 && k < strs[i].size() && strs[i][k] == c)
            {
                ans.push_back(c);
                k++;
                i = 0;
                if (k < strs[0].size())
                    c = strs[0][k];
                else
                    return ans;
            }
        }

        return ans;
    }
};
// @lc code=end
