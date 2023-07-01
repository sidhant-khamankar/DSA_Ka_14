/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */

// @lc code=start
class Solution
{
public:
    // return int recur with index, amount, coins, curr_amount
    // base condition:
    // if curr_amount == amount return 1;
    // if curr_amount > amount return 0;
    // loop for all indexes considering current index's coin

    int recur(int ind, int amount, vector<int> &coins, int curr_amount, vector<vector<int>> &dp)
    {
        // cout << ind << " " << curr_amount << endl;
        if (curr_amount == amount)
        {
            // st.insert(v);
            return dp[curr_amount][ind] = 1;
        }
        if (curr_amount > amount)
        {
            return 0;
        }

        if (dp[curr_amount][ind] != -1)
        {
            return dp[curr_amount][ind];
        }

        int ans = 0;
        for (int i = ind; i < coins.size(); i++)
        {
            // v.push_back(coins[i]);
            ans += recur(i, amount, coins, curr_amount + coins[i], dp);
            // v.pop_back();
        }

        return dp[curr_amount][ind] = ans;
    }

    int change(int amount, vector<int> &coins)
    {
        // return int recur for index 0
        // set<vector<int>> ans;
        // vector<int> v;
        // recur(0, amount, coins, 0, ans, v);
        // return ans.size();

        vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), -1));
        return recur(0, amount, coins, 0, dp);
    }
};
// @lc code=end
