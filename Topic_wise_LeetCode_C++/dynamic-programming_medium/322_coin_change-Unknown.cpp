/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution
{
public:
    // Aditya verma like unbounded knapsack like leetcode solution bottom up
    // My solution Oamount*n time Oamount*n space
    // int recur(int ind, vector<int> &coins, int amount, vector<vector<int>> &dp)
    // {

    //     if (amount < 0)
    //     {
    //         return -1;
    //     }
    //     if (dp[ind][amount] != -2)
    //         return dp[ind][amount];
    //     if (amount == 0)
    //     {
    //         return dp[ind][amount] = 0;
    //     }
    //     int mini = INT_MAX;

    //     for (int i = ind; i < coins.size(); i++)
    //     {
    //         int temp = recur(i, coins, amount - coins[i], dp);
    //         if (temp == -1)
    //             continue;
    //         mini = min(mini, 1 + temp);
    //     }

    //     if (mini == INT_MAX)
    //         return dp[ind][amount] = -1;
    //     else
    //         return dp[ind][amount] = mini;
    // }
    // int coinChange(vector<int> &coins, int amount)
    // {
    //     vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -2));
    //     return recur(0, coins, amount, dp);
    // }

    // Leetcode solution
    //  Brute force TLE Oamount^coins On space
    // public
    //     class Solution
    //     {

    //     public
    //         int coinChange(int[] coins, int amount)
    //         {
    //             return coinChange(0, coins, amount);
    //         }

    //     private
    //         int coinChange(int idxCoin, int[] coins, int amount)
    //         {
    //             if (amount == 0)
    //                 return 0;
    //             if (idxCoin < coins.length && amount > 0)
    //             {
    //                 int maxVal = amount / coins[idxCoin];
    //                 int minCost = Integer.MAX_VALUE;
    //                 for (int x = 0; x <= maxVal; x++)
    //                 {
    //                     if (amount >= x * coins[idxCoin])
    //                     {
    //                         int res = coinChange(idxCoin + 1, coins, amount - x * coins[idxCoin]);
    //                         if (res != -1)
    //                             minCost = Math.min(minCost, res + x);
    //                     }
    //                 }
    //                 return (minCost == Integer.MAX_VALUE) ? -1 : minCost;
    //             }
    //             return -1;
    //         }
    //     }

    // Time Limit Exceeded

    // Top down dp Oamount*counts time Oamount space
    // public
    //     class Solution
    //     {

    //     public
    //         int coinChange(int[] coins, int amount)
    //         {
    //             if (amount < 1)
    //                 return 0;
    //             return coinChange(coins, amount, new int[amount]);
    //         }

    //     private
    //         int coinChange(int[] coins, int rem, int[] count)
    //         {
    //             if (rem < 0)
    //                 return -1;
    //             if (rem == 0)
    //                 return 0;
    //             if (count[rem - 1] != 0)
    //                 return count[rem - 1];
    //             int min = Integer.MAX_VALUE;
    //             for (int coin : coins)
    //             {
    //                 int res = coinChange(coins, rem - coin, count);
    //                 if (res >= 0 && res < min)
    //                     min = 1 + res;
    //             }
    //             count[rem - 1] = (min == Integer.MAX_VALUE) ? -1 : min;
    //             return count[rem - 1];
    //         }
    //     }

    // bottom up dp Oamount*counts time Oamount space
    // public
    //     class Solution
    //     {
    //     public
    //         int coinChange(int[] coins, int amount)
    //         {
    //             int max = amount + 1;
    //             int[] dp = new int[amount + 1];
    //             Arrays.fill(dp, max);
    //             dp[0] = 0;
    //             for (int i = 1; i <= amount; i++)
    //             {
    //                 for (int j = 0; j < coins.length; j++)
    //                 {
    //                     if (coins[j] <= i)
    //                     {
    //                         dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
    //                     }
    //                 }
    //             }
    //             return dp[amount] > amount ? -1 : dp[amount];
    //         }
    //     }
};
// @lc code=end
