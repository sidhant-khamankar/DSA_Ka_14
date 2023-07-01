/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution
{
public:
    // did not get, Neetcode solution O1 time
    int hammingWeight(uint32_t n)
    {
        int count = 0;

        while (n)
        {
            count += n & 1;
            n >>= 1;
        }
        // More efficient - Get rid of last digit by anding n & n-1
        // res = 0
        // while n:
        //     n &= n - 1
        //     res += 1
        // return res

        return count;
    }
};
// @lc code=end
