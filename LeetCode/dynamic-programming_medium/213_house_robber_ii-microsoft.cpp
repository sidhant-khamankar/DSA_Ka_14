/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution
{
public:
    // My solution On time O1 space
    int robHelper(vector<int> nums, int start, int end)
    {
        int rob1 = 0;
        int rob2 = 0;
        for (int i = start; i < end; i++)
        {
            int temp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        return max(
            robHelper(nums, 0, nums.size() - 1),
            robHelper(nums, 1, nums.size()));
    }
};
// @lc code=end
