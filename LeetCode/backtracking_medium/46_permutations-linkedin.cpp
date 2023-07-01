/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start

class Solution
{
private:
    // Striver solution Approach 2 On!*n time On auxiliary space
    void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            recurPermute(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};
// class Solution
// {
// private:
//     //Striver solution approach 1 On!*n time On+n space
//     void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
//     {
//         if (ds.size() == nums.size())
//         {
//             ans.push_back(ds);
//             return;
//         }
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (!freq[i])
//             {
//                 ds.push_back(nums[i]);
//                 freq[i] = 1;
//                 recurPermute(ds, nums, ans, freq);
//                 freq[i] = 0;
//                 ds.pop_back();
//             }
//         }
//     }

// public:
//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         vector<vector<int>> ans;
//         vector<int> ds;
//         int freq[nums.size()];
//         for (int i = 0; i < nums.size(); i++)
//             freq[i] = 0;
//         recurPermute(ds, nums, ans, freq);
//         return ans;
//     }
// };
// class Solution
// {
// public:
//     // My solution On!*n*n time On space
//     void recur(vector<int> nums, vector<int> &ds, vector<vector<int>> &ans, int n)
//     {
//         if (ds.size() == n)
//         {
//             ans.push_back(ds);
//             return;
//         }
//         for (int i = 0; i < n; i++)
//         {
//             if (find(ds.begin(), ds.end(), nums[i]) == ds.end())
//             {
//                 ds.push_back(nums[i]);
//                 recur(nums, ds, ans, n);
//                 ds.pop_back();
//             }
//         }
//     }
//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         vector<int> ds;
//         vector<vector<int>> ans;
//         int n = nums.size();
//         recur(nums, ds, ans, n);
//         return ans;
//     }
// };

// @lc code=end
