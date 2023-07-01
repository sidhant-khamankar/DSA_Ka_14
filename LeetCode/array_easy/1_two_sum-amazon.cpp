/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    //Striver solution On time On space
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mpp.find(target - nums[i]) != mpp.end())
            {
                ans.push_back(mpp[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mpp[nums[i]] = i;
        }
        return ans;
    }

    // My solution On^2 time O1 space
    // vector<int> twoSum(vector<int> &nums, int target)
    // {
    //     vector<int> ans;
    //     for (int i = 0; i < nums.size(); i++)
    //         for (int j = i + 1; j < nums.size(); j++)
    //         {
    //             if (nums[i] + nums[j] == target)
    //             {
    //                 ans.push_back(i);
    //                 ans.push_back(j);
    //                 return ans;
    //             }
    //         }
    //     return ans;
    // }

    // dealing with indexes and duplicates cant use merge sort

    // void merge_sort(vector<int> &nums, vector<int> &ans, int target)
    // {
    //     long int n = nums.size();
    //     return _merge_sort(nums, ans, 0, n - 1, target);
    // }
    // void _merge_sort(vector<int> &nums, vector<int> &ans, long int left, long int right, int target)
    // {
    //     long int mid;
    //     if (right > left)
    //     {
    //         mid = (right + left) / 2;

    //         _merge_sort(nums, ans, left, mid, target);
    //         _merge_sort(nums, ans, mid + 1, right, target);

    //         merge(nums, ans, left, mid, right, target);
    //     }
    // }

    // void merge(vector<int> &nums, vector<int> &ans, long int left, long int mid, long int right, int target)
    // {
    //     long int i, j;

    //     vector<int> temp;
    //     i = left;
    //     j = mid + 1;
    //     while (i <= mid && (j <= right))
    //     {
    //         if (nums[i] <= nums[j])
    //         {
    //             int t = j;
    //             while ((t <= right) && (nums[i] + nums[t] < target))
    //                 t++;
    //             if ((t <= right) && nums[i] + nums[t] == target)
    //             {
    //                 ans.push_back(i);
    //                 ans.push_back(t);
    //             }
    //             temp.push_back(nums[i++]);
    //         }
    //         else
    //         {
    //             int t = i;
    //             while ((t <= mid) && (nums[t] + nums[j] < target))
    //                 t++;
    //             if ((t <= mid) && nums[t] + nums[j] == target)
    //             {
    //                 ans.push_back(t);
    //                 ans.push_back(j);
    //             }
    //             temp.push_back(nums[j++]);
    //         }
    //     }

    //     while (i <= mid)
    //         temp.push_back(nums[i++]);
    //     while (j <= right)
    //         temp.push_back(nums[j++]);

    //     for (i = left; i <= right; i++)
    //         nums[i] = temp[i - left];
    // }
    // vector<int> twoSum(vector<int> &nums, int target)
    // {
    //     vector<int> ans;
    //     merge_sort(nums, ans, target);
    //     return ans;
    // }
};
// @lc code=end
