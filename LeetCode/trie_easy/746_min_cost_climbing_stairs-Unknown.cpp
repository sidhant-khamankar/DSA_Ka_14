/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        // My solution Time limit exceeded
        // Neetcode solution On time O1 space
        // start from end and calculate minimum path from top and maintain that in cost vector

        cost.push_back(0);

        for (int i = cost.size() - 3; i >= 0; i--)
        {
            cost[i] += min(cost[i + 1], cost[i + 2]);
        }

        return min(cost[0], cost[1]);
    }
};
// @lc code=end
