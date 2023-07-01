/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution
{
public:
    //my solution recusion TLE
    // Striver Solution
    // bruteforce On^2 time On space
    // int lengthOfLIS(vector<int> &nums)
    // {
    //     int lis[n];

    //     lis[0] = 1;

    //     /* Compute optimized LIS values in
    //    bottom up manner */
    //     for (int i = 1; i < n; i++)
    //     {
    //         lis[i] = 1;
    //         for (int j = 0; j < i; j++)
    //             if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
    //                 lis[i] = lis[j] + 1;
    //     }

    //     // Return maximum value in lis[]
    //     return *max_element(lis, lis + n);
    // }

    //Efficient binary search to find immediate next larger element Onlogn time On space
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> seq;
        seq.push_back(nums[0]);

        for (int i = 1; i < n; i++)
        {
            if (seq.back() < nums[i])
                seq.push_back(nums[i]);
            else
            {
                int ind = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                seq[ind] = nums[i];
            }
        }

        return seq.size();
    }
};
// @lc code=end
