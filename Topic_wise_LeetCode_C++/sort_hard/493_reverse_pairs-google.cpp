/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution
{
public:
    // Striver Solution Onlogn time (merge sort) On space (temp array)
    // count inversions else code fails as negative numbers are there and left array item will be put first in temp array

    int merge_sort(vector<int> &nums)
    {
        long int n = nums.size();
        return _merge_sort(nums, 0, n - 1);
    }
    int _merge_sort(vector<int> &nums, long int left, long int right)
    {
        long int mid, inv_count = 0;
        if (right > left)
        {
            mid = (right + left) / 2;

            inv_count += _merge_sort(nums, left, mid);
            inv_count += _merge_sort(nums, mid + 1, right);

            inv_count += merge(nums, left, mid, right);
        }
        return inv_count;
    }

    int merge(vector<int> &nums, long int left, long int mid, long int right)
    {
        long int i, j;
        long int inv_count = 0;

        j = mid + 1;
        for (int i = left; i <= mid; i++)
        {
            while (j <= right && nums[i] > 2LL * nums[j])
            {
                j++;
            }
            inv_count += (j - (mid + 1));
        }

        vector<int> temp;
        i = left;
        j = mid + 1;
        while (i <= mid && (j <= right))
        {
            if (nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
            {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid)
            temp.push_back(nums[i++]);
        while (j <= right)
            temp.push_back(nums[j++]);

        for (i = left; i <= right; i++)
            nums[i] = temp[i - left];
        return inv_count;
    }
    int reversePairs(vector<int> &nums)
    {
        return merge_sort(nums);
    }
    // int reversePairs(vector<int> &nums)
    // {
    //     // My solution On^2 time O1 space TLE
    //         int count = 0;
    //         for (int j = nums.size() - 1; j > 0; j--)
    //         {
    //             for (int i = j - 1; i >= 0; i--)
    //             {
    //                 long long twice = (long long)nums[j] * 2;
    //                 if (nums[i] > twice)
    //                     count++;
    //             }
    //         }
    //         return count;
    // }
};
// @lc code=end
