/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution
{
public:
    // Leetcode solution

    // Bruteforce On time On space
    // void moveZeroes(vector<int> &nums)
    // {
    //     int n = nums.size();

    //     // Count the zeroes
    //     int numZeroes = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         numZeroes += (nums[i] == 0);
    //     }

    //     // Make all the non-zero elements retain their original order.
    //     vector<int> ans;
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (nums[i] != 0)
    //         {
    //             ans.push_back(nums[i]);
    //         }
    //     }

    //     // Move all zeroes to the end
    //     while (numZeroes--)
    //     {
    //         ans.push_back(0);
    //     }

    //     // Combine the result
    //     for (int i = 0; i < n; i++)
    //     {
    //         nums[i] = ans[i];
    //     }
    // }

    // Optimal On time O1 space
    // void moveZeroes(vector<int> &nums)
    // {
    //     int lastNonZeroFoundAt = 0;
    //     // If the current element is not 0, then we need to
    //     // append it just in front of last non 0 element we found.
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         if (nums[i] != 0)
    //         {
    //             nums[lastNonZeroFoundAt++] = nums[i];
    //         }
    //     }
    //     // After we have finished processing new elements,
    //     // all the non-zero elements are already at beginning of array.
    //     // We just need to fill remaining array with 0's.
    //     for (int i = lastNonZeroFoundAt; i < nums.size(); i++)
    //     {
    //         nums[i] = 0;
    //     }
    // }

    // Leetcode, Neetcode Optimal less writes
    // On time O1 space
    void moveZeroes(vector<int> &nums)
    {
        for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++)
        {
            if (nums[cur] != 0)
            {
                swap(nums[lastNonZeroFoundAt++], nums[cur]);
            }
        }
    }

    // My solution On time O1 space
    // void moveZeroes(vector<int> &nums)
    // {
    //     int zero_pointer = 0;
    //     int non_zero_pointer = 0;

    //     while (zero_pointer < nums.size() || non_zero_pointer < nums.size())
    //     {
    //         while (zero_pointer < nums.size() && nums[zero_pointer] != 0)
    //         {
    //             zero_pointer++;
    //         }

    //         while (non_zero_pointer < nums.size() && nums[non_zero_pointer] == 0)
    //         {
    //             non_zero_pointer++;
    //         }

    //         if (zero_pointer == nums.size() || non_zero_pointer == nums.size())
    //         {
    //             break;
    //         }

    //         if (zero_pointer < non_zero_pointer)
    //             swap(nums[zero_pointer], nums[non_zero_pointer]);
    //         non_zero_pointer++;
    //     }
    // }
};
// @lc code=end
