/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        // Did not get appending part, Neetcode solution O1 time O1 space
        uint32_t result = 0;

        for (int i = 0; i < 32; i++)
        {
            result <<= 1;
            result |= n & 1;
            n >>= 1;
        }

        return result;
    }
};
// @lc code=end
