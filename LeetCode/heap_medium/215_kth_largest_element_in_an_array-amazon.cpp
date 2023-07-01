/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution
{
public:
    // Leetcode discuss solution quickselect
    int findKthLargest(vector<int> &nums, int k)
    {
        int left = 0, right = nums.size() - 1, kth;
        while (true)
        {
            int idx = partition(nums, left, right);
            if (idx == k - 1)
            {
                kth = nums[idx];
                break;
            }
            if (idx < k - 1)
            {
                left = idx + 1;
            }
            else
            {
                right = idx - 1;
            }
        }
        return kth;
    }

    int partition(vector<int> &nums, int left, int right)
    {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r)
        {
            if (nums[l] < pivot && nums[r] > pivot)
            {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot)
            {
                l++;
            }
            if (nums[r] <= pivot)
            {
                r--;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
    // Code library gfg solution
    // Max heap On+klogn time, then pop k times to get kth largest
    // My solution Onlogn time O1 space
    // int findKthLargest(vector<int> &nums, int k)
    // {
    //     sort(nums.begin(), nums.end(), greater<int>());
    //     return nums[k - 1];
    // }
};
// @lc code=end
