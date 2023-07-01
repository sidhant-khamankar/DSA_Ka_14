/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution
{
public:
    // My solution like Lead coding by fraz solution  O2^9 time O2^9 space
    void recur(int ind, int curr_sum, int k, int n, vector<int> &curr, vector<vector<int>> &ans)
    {
        if (curr_sum == n && curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }
        if (ind > 9 || curr.size() > k || curr_sum > n)
        {
            return;
        }

        curr.push_back(ind);
        recur(ind + 1, curr_sum + ind, k, n, curr, ans);
        curr.pop_back();

        recur(ind + 1, curr_sum, k, n, curr, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> curr;

        recur(1, 0, k, n, curr, ans);
        return ans;
    }
};
// @lc code=end
