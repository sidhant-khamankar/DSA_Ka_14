/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start

class Solution
{
public:
    // Striver solution 2^n+k length of combination time k* combinations space
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++)
        {
            if (i > ind && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;
            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
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

//         for (int i = ind + 1; i < n; i++)
//         {
//             if (ind + 1 != i && candidates[i] == candidates[i - 1])
//                 continue;
//             else if (target - candidates[i] < 0)
//                 break;
//             else if (target - candidates[i] == 0)
//             {
//                 ds.push_back(candidates[i]);
//                 ans.push_back(ds);
//                 ds.pop_back();
//                 break;
//             }
//             else
//             {
//                 ds.push_back(candidates[i]);
//                 recur(i, n, ans, ds, target - candidates[i], candidates);
//                 ds.pop_back();
//             }
//         }
//     }
//     vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
//     {
//         vector<vector<int>> ans;
//         vector<int> ds;
//         int n = candidates.size();
//         sort(candidates.begin(), candidates.end());
//         recur(-1, n, ans, ds, target, candidates);

//         return ans;
//     }
// };
// @lc code=end
