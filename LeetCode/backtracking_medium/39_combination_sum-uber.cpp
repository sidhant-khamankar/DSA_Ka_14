/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start

// Striver solution O2^k*k time k*x combinations space
class Solution
{
public:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (ind == arr.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        // pick up the element
        if (arr[ind] <= target)
        {
            ds.push_back(arr[ind]);
            findCombination(ind, target - arr[ind], arr, ans, ds);
            ds.pop_back();
        }

        findCombination(ind + 1, target, arr, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
// class Solution
// {
// public:
//     // My solution 2^n*n time 2^n*k space auxiliary space of recursion calls On
//     void recur(int ind, int n, vector<vector<int>> &ans, vector<int> &ds, int target, vector<int> candidates)
//     {
//         if (target == 0)
//         {
//             ans.push_back(ds);
//             return;
//         }
//         for (int i = ind; i < n; i++)
//         {
//             if (target - candidates[i] < 0)
//                 break;
//             else
//             {
//                 ds.push_back(candidates[i]);
//                 recur(i, n, ans, ds, target - candidates[i], candidates);
//                 ds.pop_back();
//             }
//         }
//     }

//     vector<vector<int>> combinationSum(vector<int> &candidates, int target)
//     {
//         vector<vector<int>> ans;
//         vector<int> ds;
//         int n = candidates.size();
//         sort(candidates.begin(), candidates.end());
//         recur(0, n, ans, ds, target, candidates);

//         return ans;
//     }
// };
// @lc code=end
