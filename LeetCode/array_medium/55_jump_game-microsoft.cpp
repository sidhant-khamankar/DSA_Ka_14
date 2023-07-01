/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution
{
public:
    // My solution On time On space
    // Neetcode solution greedy On time O1 space
    bool canJump(vector<int> &nums)
    {
        int goal = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] + i >= goal)
            {
                goal = i;
            }
        }
        return goal == 0;
    }

    // bool recur(int ind, vector<int> &nums, vector<int> &dp)
    // {
    //     if (ind == nums.size() - 1)
    //         return dp[ind] = true;

    //     if (ind >= nums.size())
    //         return false;

    //     if (dp[ind] != -1)
    //         return dp[ind];

    //     bool res = false;

    //     for (int i = 1; i <= nums[ind]; i++)
    //     {
    //         // cout << "Ind: " << ind << " Nums[i]: " << nums[i] << endl;
    //         res = res || recur(ind + i, nums, dp);
    //         if (res == true)
    //             break;
    //     }

    //     return dp[ind] = res;
    // }
    // bool canJump(vector<int> &nums)
    // {
    //     vector<int> dp(nums.size() + 1, -1);
    //     return recur(0, nums, dp);
    // }
};
// @lc code=end
