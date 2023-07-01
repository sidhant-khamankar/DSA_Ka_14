/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
class Solution
{
public:
    // did not get, answer less than 5 for sample test case, 1.30 hrs
    // Tech dose solution
    // Recursion time complexity: permutations: n! and to calculate points: On
    // Total: On!n time
    // Dp: On^3 time
    // Top down - tabulation

    // Leetcode discuss memoization On^3 time On^2 space

    int MCM(vector<int> &nums, int left, int right, vector<vector<int>> &mem) //Matrix Chain Multiplication Problem
    {
        if (left >= right)
            return 0;

        if (mem[left][right] != -1)
            return mem[left][right];

        int max_cost = INT_MIN;

        for (int k = left; k < right; k++)
        {
            int total_cost = MCM(nums, left, k, mem) + MCM(nums, k + 1, right, mem) + nums[left - 1] * nums[k] * nums[right];

            max_cost = max(max_cost, total_cost);

            mem[left][right] = max_cost;
        }
        return mem[left][right];
    }
    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1); //for inserting value in front of vector array by vec_name.insert(pos,val);
        nums.push_back(1);            //Inserting 1 at the end of nums vector array

        int n = nums.size();
        vector<vector<int>> mem(n, vector<int>(n, -1));

        return MCM(nums, 1, n - 1, mem);
    }
};
// @lc code=end
