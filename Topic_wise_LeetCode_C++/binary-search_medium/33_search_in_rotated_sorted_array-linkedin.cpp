/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    //Striver solution Ologn time O1 space
    int search(vector<int> &a, int target)
    {
        int low = 0, high = a.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (a[mid] == target)
                return mid;

            // the left side is sorted
            if (a[low] <= a[mid])
            {
                if (target >= a[low] && target <= a[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (target >= a[mid] && target <= a[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }

    // My solution Ologn time O1 space
    // int search(vector<int> &nums, int target)
    // {
    //     int low = 0;
    //     int n = nums.size();
    //     int high = n - 1;
    //     while (low < high)
    //     {
    //         int mid = (low + high) / 2;
    //         if (target <= nums[n - 1] && nums[mid] > nums[n - 1])
    //             low = mid + 1;
    //         else if (target <= nums[n - 1] && nums[mid] <= nums[n - 1])
    //         {
    //             if (target < nums[mid])
    //                 high = mid - 1;
    //             else if (target > nums[mid])
    //                 low = mid + 1;
    //             else
    //                 return mid;
    //         }
    //         else if (target > nums[n - 1] && nums[mid] > nums[n - 1])
    //         {
    //             if (target < nums[mid])
    //                 high = mid - 1;
    //             else if (target > nums[mid])
    //                 low = mid + 1;
    //             else
    //                 return mid;
    //         }
    //         else if (target > nums[n - 1] && nums[mid] <= nums[n - 1])
    //             high = mid - 1;
    //     }

    //     if (target == nums[low])
    //         return low;
    //     else
    //         return -1;
    // }
};
// @lc code=end
