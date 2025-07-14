# Striver Solution
'''
```
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
```

# My solutions
```
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
```
'''

# Neetcode solution
'''
Divide and conquer
time - O(nlogn)
space - O(logn)
```
'''
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        def dfs(l, r):
            if l > r:
                return float("-inf")

            m = (l + r) >> 1
            leftSum = rightSum = curSum = 0
            for i in range(m - 1, l - 1, -1):
                curSum += nums[i]
                leftSum = max(leftSum, curSum)

            curSum = 0
            for i in range(m + 1, r + 1):
                curSum += nums[i]
                rightSum = max(rightSum, curSum)

            return (max(dfs(l, m - 1), 
                        dfs(m + 1, r), 
                        leftSum + nums[m] + rightSum))
                        
        return dfs(0, len(nums) - 1)
'''
```
'''