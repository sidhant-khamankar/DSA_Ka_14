/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int cnt = 0;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }

            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};
// class Solution
// {
// public:
//     // My solution On time O1 space
//     int findMaxConsecutiveOnes(vector<int> &nums)
//     {
//         int ans = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] == 1)
//             {
//                 int j = i;
//                 int count = 1;
//                 while (j + 1 < nums.size() && nums[j] == nums[j + 1])
//                 {
//                     j++;
//                     count++;
//                 }
//                 ans = max(ans, count);
//                 j++;
//                 i = j;
//             }
//         }
//         return ans;
//     }
// };
// @lc code=end
