/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start

//Striver solution On time O1 space like my solution
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        int i = 0;

        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};

// class Solution
// {
// public:
//     // My solution On time O1 space
//     int removeDuplicates(vector<int> &nums)
//     {
//         if (nums.size() <= 1)
//         {
//             return nums.size();
//         }

//         int curr = 1;
//         int i = 1;

//         while (i < nums.size())
//         {
//             while (nums[i - 1] == nums[i])
//             {
//                 i++;
//                 if (i > nums.size() - 1)
//                     break;
//             }
//             if (i < nums.size())
//                 nums[curr++] = nums[i++];
//         }

//         return curr;
//     }
// };
// @lc code=end
