/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution
{
public:
    //did not get optimal can be done with On time On space hashmap or On^2 time O1 space

    // Leecode discuss, tech dose On time O1 space
    int singleNumber(vector<int> &A)
    {
        int n = A.size();
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result ^= A[i];
        }
        return result;
    }
};
// @lc code=end
