/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution
{
public:
    // Neetcode, Leetcode solution similar to My solution On time O1 space
    // class Solution
    // {
    // public
    //     int pivotIndex(int[] nums)
    //     {
    //         int sum = 0, leftsum = 0;
    //         for (int x : nums)
    //             sum += x;
    //         for (int i = 0; i < nums.length; ++i)
    //         {
    //             if (leftsum == sum - leftsum - nums[i])
    //                 return i;
    //             leftsum += nums[i];
    //         }
    //         return -1;
    //     }
    // }

    // My solution On time O1 space
    int pivotIndex(vector<int> &nums)
    {

        int n = nums.size();
        if (n == 1)
            return nums[0];

        int left_sum = 0;
        int right_sum = 0;

        for (int i = 1; i < n; i++)
        {
            right_sum += nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {
                left_sum += nums[i - 1];
                right_sum -= nums[i];
            }

            if (left_sum == right_sum)
            {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end
