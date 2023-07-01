/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */

// @lc code=start
class Solution
{
public:
    // did not get
    // KnowledgeCentre solution Ovalid time On space
    // Leetcode solution, Backtracking
    void calculate(int n, int pos, vector<bool> &visited, int &count)
    {
        if (pos > n)
            count++;
        for (int i = 1; i <= n; ++i)
        {
            if (!visited[i] && (pos % i == 0 || i % pos == 0))
            {
                visited[i] = true;
                calculate(n, pos + 1, visited, count);
                visited[i] = false;
            }
        }
    }
    int countArrangement(int n)
    {
        vector<bool> visited(n + 1, false);
        int count = 0;
        calculate(n, 1, visited, count);
        return count;
    }

    // Leetcode solution find all permutations swapping index with all rights, On! time On space TLE

    // public
    //     class Solution
    //     {
    //         int count = 0;
    //     public
    //         int countArrangement(int N)
    //         {
    //             int[] nums = new int[N];
    //             for (int i = 1; i <= N; i++)
    //                 nums[i - 1] = i;
    //             permute(nums, 0);
    //             return count;
    //         }
    //     public
    //         void permute(int[] nums, int l)
    //         {
    //             if (l == nums.length - 1)
    //             {
    //                 int i;
    //                 for (i = 1; i <= nums.length; i++)
    //                 {
    //                     if (nums[i - 1] % i != 0 && i % nums[i - 1] != 0)
    //                         break;
    //                 }
    //                 if (i == nums.length + 1)
    //                 {
    //                     count++;
    //                 }
    //             }
    //             for (int i = l; i < nums.length; i++)
    //             {
    //                 swap(nums, i, l);
    //                 permute(nums, l + 1);
    //                 swap(nums, i, l);
    //             }
    //         }
    //     public
    //         void swap(int[] nums, int x, int y)
    //         {
    //             int temp = nums[x];
    //             nums[x] = nums[y];
    //             nums[y] = temp;
    //         }
    //     }

    // Leetcode solution better brute force Ovalid time On space

    // public
    //     class Solution
    //     {
    //         int count = 0;
    //     public
    //         int countArrangement(int N)
    //         {
    //             int[] nums = new int[N];
    //             for (int i = 1; i <= N; i++)
    //                 nums[i - 1] = i;
    //             permute(nums, 0);
    //             return count;
    //         }
    //     public
    //         void permute(int[] nums, int l)
    //         {
    //             if (l == nums.length)
    //             {
    //                 count++;
    //             }
    //             for (int i = l; i < nums.length; i++)
    //             {
    //                 swap(nums, i, l);
    //                 if (nums[l] % (l + 1) == 0 || (l + 1) % nums[l] == 0)
    //                     permute(nums, l + 1);
    //                 swap(nums, i, l);
    //             }
    //         }
    //     public
    //         void swap(int[] nums, int x, int y)
    //         {
    //             int temp = nums[x];
    //             nums[x] = nums[y];
    //             nums[y] = temp;
    //         }
    //     }
};
// @lc code=end
