/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution
{
public:
    //Striver solution
    // 1. On^3
    // for i->0 to n-1
    // 	for j ->i to n-1
    // 		for k -> i to j
    // 			find sum
    // 		max_sum

    // 2. On^2
    // for i->0 to n-1
    // 	sum=0
    // 	for j ->i to n-1
    // 		sum+=a[j]
    // 		maxi = max(maxi, sum)

    // 3. On O1 space Kadane Algorithm
    // sum=0
    // maxi = a[0]
    // loop
    // 	sum+=a[i-1]
    // 	change sum to 0 if sum<0
    // 	compare maxi with sum and upate if maxi is lesser

    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maxi = INT_MIN;
        for (auto it : nums)
        {
            sum += it;
            maxi = max(sum, maxi);
            if (sum < 0)
                sum = 0;
        }
        return maxi;
    }

    // leetcode discuss solution
    // int maxSubArray(int[] A)
    // { //On time
    //     int n = A.length;
    //     int[] dp = new int[n]; //dp[i] means the maximum subarray ending with A[i];
    //     dp[0] = A[0];
    //     int max = dp[0];

    //     for (int i = 1; i < n; i++)
    //     {
    //         dp[i] = A[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
    //         max = Math.max(max, dp[i]);
    //     }

    //     return max;
    // }

    //My solution
    // int maxSubArray(vector<int> &nums)
    // {
    //     // On^2 time and On space (not needed)
    //     int largest = INT_MIN;
    //     // vector<int> sub;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         int curr_sum = 0;
    //         // vector<int> curr_sub;
    //         for (int j = i; j < nums.size(); j++)
    //         {
    //             curr_sum += nums[j];
    //             // curr_sub.emplace_back(nums[j]);
    //             if (curr_sum > largest)
    //             {
    //                 largest = curr_sum;
    //                 // sub=curr_sub;
    //             }
    //         }
    //     }
    //     return largest;
    // }
};
// @lc code=end
