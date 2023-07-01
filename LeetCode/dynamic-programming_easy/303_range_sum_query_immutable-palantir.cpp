/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray
{
public:
    // Jayati Tiwari, Leetcode solution
    // Bruteforce TLE On per query time

    // private
    //     int[] data;

    // public
    //     NumArray(int[] nums)
    //     {
    //         data = nums;
    //     }

    // public
    //     int sumRange(int i, int j)
    //     {
    //         int sum = 0;
    //         for (int k = i; k <= j; k++)
    //         {
    //             sum += data[k];
    //         }
    //         return sum;
    //     }

    // Hashmap On^2 computation time and O1 query time On^2 space
    // private
    //     Map<Pair<Integer, Integer>, Integer> map = new HashMap<>();

    // public
    //     NumArray(int[] nums)
    //     {
    //         for (int i = 0; i < nums.length; i++)
    //         {
    //             int sum = 0;
    //             for (int j = i; j < nums.length; j++)
    //             {
    //                 sum += nums[j];
    //                 map.put(Pair.create(i, j), sum);
    //             }
    //         }
    //     }

    // public
    //     int sumRange(int i, int j)
    //     {
    //         return map.get(Pair.create(i, j));
    //     }

    // Caching like my solution O1 query time On pre computation time On space
    // private
    //     int[] sum; //declare

    // public
    //     NumArray(int[] nums)
    //     {
    //         sum = new int[nums.length + 1]; // initialize the size using dynamic memory allocation
    //         for (int i = 0; i < nums.length; i++)
    //         {
    //             sum[i + 1] = sum[i] + nums[i];
    //         }
    //     }

    // public
    //     int sumRange(int i, int j)
    //     {
    //         return sum[j + 1] - sum[i];
    //     }

    // my solution On time On space to create O1 query time
    vector<int> dp;
    NumArray(vector<int> &nums)
    {
        dp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            dp.push_back(nums[i] + dp[i - 1]);
        }
    }

    int sumRange(int left, int right)
    {
        if (left > 0)
        {
            return dp[right] - dp[left - 1];
        }
        else
            return dp[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
