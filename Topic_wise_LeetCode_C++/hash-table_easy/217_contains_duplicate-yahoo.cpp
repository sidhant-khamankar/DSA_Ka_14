/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution
{
public:
    // Neetcode solution
    // Double loops On^2 time O1 space
    // Sorting and then iterating Onlogn time O1 space
    // Hashset On time On space

    // My, Neetcode solution
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> st;
        for (int e : nums)
        {
            if (st.find(e) != st.end())
            {
                return true;
            }
            else
            {
                st.insert(e);
            }
        }
        return false;
    }
};
// @lc code=end
