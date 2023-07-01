/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // Brute On time On space using Freq map then return highest frequency's key
        int max_times = nums.size() / 2;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) != m.end())
                m[nums[i]]++;
            else
                m[nums[i]] = 1;
        }

        int max_freq = -1;
        int max_key;
        map<int, int>::iterator itr;
        for (itr = m.begin(); itr != m.end(); ++itr)
        {
            if (max_freq < itr->second)
            {
                max_key = itr->first;
                max_freq = itr->second;
            }
        }
        return max_key;
    }
};
// @lc code=end