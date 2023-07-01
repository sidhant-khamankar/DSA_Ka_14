/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start

//Striver solution On time O1 space
class Solution
{
public:
    int trap(vector<int> &height)
    {

        int n = height.size();
        int left = 0;
        int right = n - 1;
        int res = 0;
        int maxleft = 0, maxright = 0;

        while (left <= right)
        {

            if (height[left] <= height[right])
            {

                if (height[left] >= maxleft)
                    maxleft = height[left];
                else
                    res += maxleft - height[left];

                left++;
            }
            else
            {

                if (height[right] >= maxright)
                    maxright = height[right];
                else
                    res += maxright - height[right];

                right--;
            }
        }
        return res;
    }
};

//My solution On^2 time O1 space
// class Solution
// {
// public:
//     int trap(vector<int> &height)
//     {
//         int ans = 0;
//         for (int i = 0; i < height.size(); i++)
//         {
//             int left = height[i];
//             int ileft = i;
//             int right = height[i];
//             int iright = i;
//             while (ileft >= 0 && height[ileft] <= left)
//             {
//                 ileft--;
//                 if (ileft != -1 && height[ileft] >= left)
//                     left = height[ileft];
//             }
//             while (iright < height.size() && height[iright] <= right)
//             {
//                 iright++;
//                 if (iright != height.size() && height[iright] >= right)
//                     right = height[iright];
//             }
//             ans += min(left, right) - height[i];
//         }

//         return ans;
//     }
// };
// @lc code=end
