/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start

class Solution
{
public:
    //Striver solution Ologn time O1 space
    int singleNonDuplicate(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 2;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (nums[mid] == nums[mid ^ 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return nums[low];
    }

    //My solution Ologn time O1 space
    // int singleNonDuplicate(vector<int> &nums)
    // {
    //     int low = 0;
    //     int high = nums.size() - 1;
    //     int n = nums.size();
    //     while (low < high)
    //     {
    //         int mid = (low + high) / 2;
    //         if (mid - 1 >= 0 && mid + 1 < n)
    //         {
    //             if (nums[mid - 1] == nums[mid])
    //             {
    //                 if ((mid + 1) % 2 == 0)
    //                     low = mid + 1;
    //                 else
    //                     high = mid - 1;
    //             }

    //             else if (nums[mid + 1] == nums[mid])
    //             {
    //                 if ((n - mid) % 2 == 0)
    //                     high = mid - 1;
    //                 else
    //                     low = mid + 1;
    //             }
    //             else
    //                 return nums[mid];
    //         }
    //         else
    //             return nums[mid];
    //     }
    //     return nums[low];
    // }
};
// @lc code=end
