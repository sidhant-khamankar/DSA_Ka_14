/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */

// @lc code=start
class Solution
{
public:
    // Leetcode solution, Knowledge center, My solution On time On space
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            ans.push_back(ans[i - 1] + nums[i]);
        }

        return ans;
    }
};
// @lc code=end
