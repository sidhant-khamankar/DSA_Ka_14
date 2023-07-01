/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    // did not get
    // Neetcode memoization dp solution On time, recursive tree O2 ^ n as height of tree is n
    // Optimal : bottom up dp starting from last step and marking ans in last and second last step as 1
    // then adding two values which are ahead for current value in dp
    // return dp[0] 0th step
    int climbStairs(int n)
    {
        int one = 1, two = 1;
        for (int i = 0; i < n - 1; i++)
        {
            int temp = one;
            one = one + two;
            two = temp;
        }
        return one;
    }
};
// @lc code=end
