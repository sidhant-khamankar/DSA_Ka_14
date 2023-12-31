/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution
{
public:
    // My solution, Nick white On time O1 space
    void reverseString(vector<char> &s)
    {
        int i = 0, j = s.size() - 1;

        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};
// @lc code=end
