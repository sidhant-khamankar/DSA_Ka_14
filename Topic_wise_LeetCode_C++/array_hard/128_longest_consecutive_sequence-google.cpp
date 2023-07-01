/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // sort and check for consecutiveness Onlogn time On space
        if (nums.empty())
            return 0;
        else if (nums.size() == 1)
            return 1;

        sort(nums.begin(), nums.end());
        int len = 1;
        set<int> s;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
                continue;
            else if (nums[i - 1] + 1 == nums[i])
                len++;
            else
            {
                s.insert(len);
                len = 1;
            }
        }
        int ans = 0;
        if (!s.empty())
        {
            auto itr = s.end();
            itr--;
            ans = *itr;
        }

        return max(ans, len);
    }
};
// @lc code=end
