/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution
{
public:
    // My solution On time O1 space binary search search range, two pointers
    // Neetcode solution

    vector<int> twoSum(vector<int> &numbers, int target)
    {

        int i = 0;
        int j = numbers.size() - 1;

        vector<int> result;

        while (i < j)
        {
            int sum = numbers[i] + numbers[j];
            if (sum < target)
            {
                i++;
            }
            else if (sum > target)
            {
                j--;
            }
            else
            {
                result.push_back(i + 1);
                result.push_back(j + 1);
                break;
                //  return {i + 1, j + 1};
            }
        }

        return result;
    }
};
// @lc code=end
