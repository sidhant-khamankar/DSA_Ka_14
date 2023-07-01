/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
public:
    // Mine TLE
    // Neetcode solution On time
    int rob(vector<int> &nums)
    {
        int rob1 = 0, rob2 = 0;

        for (int n : nums)
        {
            int temp = max(n + rob1, rob2); // adjacent 2 steps away +current, adjacent
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
        // return 1;
    }
};
// @lc code=end
