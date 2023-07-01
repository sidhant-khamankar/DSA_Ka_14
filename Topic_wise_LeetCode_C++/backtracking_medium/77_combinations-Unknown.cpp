/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution
{
public:
    // Lead coding by fraz like My solution with one more base condition
    // O2^n time O2^n space
    void help(int i, int n, int k, vector<int> &subSet, vector<vector<int>> &ans)
    {
        if (k == 0) // subset size hit limit
        {
            ans.push_back(subSet);
            return;
        }
        if (k > n - i + 1) // Remaining elements are more than choices available
            return;
        if (i > n) // all choices exhausted
            return;
        // take the ith ele
        subSet.push_back(i);
        help(i + 1, n, k - 1, subSet, ans);
        // skip the ith ele
        subSet.pop_back();
        help(i + 1, n, k, subSet, ans);
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> subSet;
        vector<vector<int>> ans;
        help(1, n, k, subSet, ans);
        return ans;
    }

    // My solution O2^n time O2^n space
    // void recur(int ind, int n, int k, vector<int> &curr, vector<vector<int>> &ans)
    // {
    //     if (curr.size() == k)
    //     {
    //         ans.push_back(curr);
    //         return;
    //     }

    //     if (ind > n)
    //     {
    //         return;
    //     }

    //     recur(ind + 1, n, k, curr, ans);
    //     curr.push_back(ind);
    //     recur(ind + 1, n, k, curr, ans);
    //     curr.pop_back();
    // }

    // vector<vector<int>> combine(int n, int k)
    // {
    //     vector<vector<int>> ans;

    //     vector<int> curr;

    //     recur(1, n, k, curr, ans);

    //     sort(ans.begin(), ans.end());
    //     return ans;
    // }
};
// @lc code=end
