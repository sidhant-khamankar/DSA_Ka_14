/*
 * @lc app=leetcode id=775 lang=cpp
 *
 * [775] Global and Local Inversions
 */

// @lc code=start
class Solution
{
public:
    // Striver Solution Onlogn time (merge sort) On space (temp array)
    int merge_sort(vector<int> &nums)
    {
        long int n = nums.size();
        vector<int> temp(n);
        return _merge_sort(nums, temp, 0, n - 1);
    }
    int _merge_sort(vector<int> &nums, vector<int> &temp, long int left, long int right)
    {
        long int mid, inv_count = 0;
        if (right > left)
        {
            mid = (right + left) / 2;

            inv_count += _merge_sort(nums, temp, left, mid);
            inv_count += _merge_sort(nums, temp, mid + 1, right);

            inv_count += merge(nums, temp, left, mid + 1, right);
        }
        return inv_count;
    }

    int merge(vector<int> &nums, vector<int> &temp, long int left, long int mid, long int right)
    {
        long int i, j, k;
        long int inv_count = 0;

        i = left;
        j = mid;
        k = left;

        while ((i <= mid - 1) && (j <= right))
        {
            if (nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
            {
                temp[k++] = nums[j++];
                inv_count = inv_count + (mid - i);
            }
        }

        while (i <= mid - 1)
            temp[k++] = nums[i++];
        while (j <= right)
            temp[k++] = nums[j++];

        for (i = left; i <= right; i++)
            nums[i] = temp[i];
        return inv_count;
    }
    bool isIdealPermutation(vector<int> &nums)
    {
        long int local = 0;
        for (long int i = 0; (i + 1) < nums.size(); i++)
        {
            if (nums[i] > nums[i + 1])
                local++;
        }
        long int global = merge_sort(nums);
        if (local == global)
            return true;
        else
            return false;

        // TLE On*nlogn time > 10^8 as n = 10^5
        //     int n = nums.size();
        //     int local = 0;
        //     for (int i = 0; i + 1 < n; i++)
        //     {
        //         if (nums[i] > nums[i + 1])
        //             local++;
        //     }
        //     int mini = n - 1;
        //     int maxi;

        //     int i = n - 1, j = n - 1;
        //     int global = 0;
        //     while (((j - 1) >= 0) && (nums[j - 1] >= nums[i]))
        //     {
        //         i--;
        //         j--;
        //     }
        //     maxi = j;

        //     global += ((n - 1 - maxi) * (n - maxi)) / 2;

        //     if (maxi == 0)
        //     {
        //         if (local == global)
        //             return true;
        //         else
        //             return false;
        //     }

        //     for (int k = maxi; k - 1 >= 0; k--)
        //     {
        //         if (nums[k - 1] > nums[maxi])
        //         {
        //             global += n - maxi;
        //             maxi--;
        //         }
        //         else if (nums[k - 1] == nums[maxi])
        //         {
        //             global += maxi - n;
        //             maxi--;
        //         }
        //         else
        //         {
        //             if (nums[k - 1] <= nums[mini])
        //             {
        //                 maxi--;
        //                 sort(nums.begin() + maxi, nums.end(), greater<int>());
        //             }
        //             else
        //             {
        //                 int mi = n - 1;
        //                 while (nums[mi] <= nums[k - 1])
        //                     mi--;
        //                 global += mini - mi;
        //                 maxi--;
        //                 sort(nums.begin() + maxi, nums.end(), greater<int>());
        //             }
        //         }
        //     }
        //     // cout << local << " " << global << endl;
        //     // for (int i = 0; i < n; i++)
        //     // {
        //     //     cout << nums[i] << " ";
        //     // }
        //     //
        //     if (local == global)
        //         return true;
        //     else
        //         return false;
    }
};
// @lc code=end