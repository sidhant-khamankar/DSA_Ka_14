/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution
{
public:
    // Did not get, Neetcode with discuss solution O1 time bitwise xor and and with left shift
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            int carry = a & b;
            a = a ^ b;
            b = (unsigned)carry << 1;
        }
        return a;
    }
};
// @lc code=end
