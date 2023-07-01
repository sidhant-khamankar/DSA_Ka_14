/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    // My solution, Aditya verma Oexponential time Oexponential space
    void recur(int ind, vector<int> &nums, vector<vector<int>> &ans, vector<int> temp)
    {
        if (ind == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        recur(ind + 1, nums, ans, temp);
        temp.pop_back();
        recur(ind + 1, nums, ans, temp);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        recur(0, nums, ans, temp);

        return ans;
    }
};
// @lc code=end
