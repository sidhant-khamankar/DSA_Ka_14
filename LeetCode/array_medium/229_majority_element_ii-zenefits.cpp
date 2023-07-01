/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // Striver Solution Bayer Moore Voting Algorithm On+On time O1 space
        int sz = nums.size();
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
        for (i = 0; i < sz; i++)
        {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
            else if (count1 == 0)
            {
                num1 = nums[i];
                count1 = 1;
            }
            else if (count1 == 0)
            {
                num2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1 = count2 = 0;
        for (i = 0; i < sz; i++)
        {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
        }
        if (count1 > sz / 3)
            ans.push_back(num1);
        if (count2 > sz / 3)
            ans.push_back(num2);
        return ans;

        // Brute Onlogn if map and On^2 if unordered map time On space
        // int max_times = nums.size() / 3;
        // map<int, int> m;
        // vector<int> ans;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (m.find(nums[i]) != m.end())
        //     {
        //         m[nums[i]]++;
        //     }
        //     else
        //     {
        //         m[nums[i]] = 1;
        //     }
        // }
        // for (auto itr = m.begin(); itr != m.end(); itr++)
        // {
        //     if ((itr->second > max_times))
        //         ans.emplace_back(itr->first);
        // }

        // return ans;
    }
};
// @lc code=end
