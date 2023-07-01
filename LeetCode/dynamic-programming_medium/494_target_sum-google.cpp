/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution
{
public:
    // Aditya verma, My solution recursion O2^n time On recursion stack space
    void recur(int ind, int &ans, int sum, vector<int> &nums, int &target)
    {
        if (sum == target && ind == nums.size())
        {
            ans++;
            return;
        }
        if (ind == nums.size())
            return;
        recur(ind + 1, ans, sum - nums[ind], nums, target);
        recur(ind + 1, ans, sum + nums[ind], nums, target);
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int ans = 0;
        recur(0, ans, 0, nums, target);
        return ans;
    }

    // Leetcode solution memoization, O(sum of nums)n time O(sum of nums)n space
    // public
    //     class Solution
    //     {
    //         int total;

    //     public
    //         int findTargetSumWays(int[] nums, int S)
    //         {
    //             total = Arrays.stream(nums).sum();

    //             int[][] memo = new int[nums.length][2 * total + 1];
    //             for (int[] row : memo)
    //             {
    //                 Arrays.fill(row, Integer.MIN_VALUE);
    //             }
    //             return calculate(nums, 0, 0, S, memo);
    //         }

    //     public
    //         int calculate(int[] nums, int i, int sum, int S, int[][] memo)
    //         {
    //             if (i == nums.length)
    //             {
    //                 if (sum == S)
    //                 {
    //                     return 1;
    //                 }
    //                 else
    //                 {
    //                     return 0;
    //                 }
    //             }
    //             else
    //             {
    //                 if (memo[i][sum + total] != Integer.MIN_VALUE)
    //                 {
    //                     return memo[i][sum + total];
    //                 }
    //                 int add = calculate(nums, i + 1, sum + nums[i], S, memo);
    //                 int subtract = calculate(nums, i + 1, sum - nums[i], S, memo);
    //                 memo[i][sum + total] = add + subtract;
    //                 return memo[i][sum + total];
    //             }
    //         }
    //     }

    // Leetcode solution 2D dp Otn time Otn space, t -> sum of nums, n -> length of nums
    // public
    //     class Solution
    //     {
    //     public
    //         int findTargetSumWays(int[] nums, int S)
    //         {
    //             int total = Arrays.stream(nums).sum();
    //             int[][] dp = new int[nums.length][2 * total + 1];
    //             dp[0][nums[0] + total] = 1;
    //             dp[0][-nums[0] + total] += 1;

    //             for (int i = 1; i < nums.length; i++)
    //             {
    //                 for (int sum = -total; sum <= total; sum++)
    //                 {
    //                     if (dp[i - 1][sum + total] > 0)
    //                     {
    //                         dp[i][sum + nums[i] + total] += dp[i - 1][sum + total];
    //                         dp[i][sum - nums[i] + total] += dp[i - 1][sum + total];
    //                     }
    //                 }
    //             }

    //             return Math.abs(S) > total ? 0 : dp[nums.length - 1][S + total];
    //         }
    //     }

    // Leetcode solution 1D dp Otn time Ot space, t -> sum of nums, n -> length of nums
    // public
    //     class Solution
    //     {
    //     public
    //         int findTargetSumWays(int[] nums, int S)
    //         {
    //             int total = Arrays.stream(nums).sum();
    //             int[] dp = new int[2 * total + 1];
    //             dp[nums[0] + total] = 1;
    //             dp[-nums[0] + total] += 1;

    //             for (int i = 1; i < nums.length; i++)
    //             {
    //                 int[] next = new int[2 * total + 1];
    //                 for (int sum = -total; sum <= total; sum++)
    //                 {
    //                     if (dp[sum + total] > 0)
    //                     {
    //                         next[sum + nums[i] + total] += dp[sum + total];
    //                         next[sum - nums[i] + total] += dp[sum + total];
    //                     }
    //                 }
    //                 dp = next;
    //             }

    //             return Math.abs(S) > total ? 0 : dp[S + total];
    //         }
    //     }
};
// @lc code=end
