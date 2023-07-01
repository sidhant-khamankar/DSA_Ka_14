/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution
{
public:
    // did not get

    //GFG solution
    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (int i = 0; i <= n; i++)
        {
            int j = i;
            int sets = 0;
            while (j)
            {
                sets += j & 1;
                j >>= 1;
            }
            ans.push_back(sets);
        }

        return ans;
    }
};
// @lc code=end
