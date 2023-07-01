// Leetcode discuss solution On time O1 space
// either IDIDI or DIDIDID
// increasing decreasing alternate as only increasing then middle may come out to be average, same with decreasing
// average of two numbers can never be lower than the smallest of the two elements, nor higher than the largest of the two elements.
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if ((nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) || (nums[i - 1] > nums[i] && nums[i] > nums[i + 1]))
            {
                int tmp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = tmp;
            }
        }
        return nums;
    }
};

// did not get WA on submit

// class Solution
// {
// public:
//     vector<int> rearrangeArray(vector<int> &nums)
//     {
//         for (int i = 1; i < nums.size() - 1; i++)
//         {
//             if ((nums[i - 1] + nums[i + 1]) / 2 == nums[i])
//                 swap(nums[i], nums[i + 1]);
//         }

//         return nums;
//     }
// };