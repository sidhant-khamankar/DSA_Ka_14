/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution
{
public:
    // scaler academy Ologn time O1 space
    // not working
    int divide(int n, int m)
    {
        long long dividend = n;
        long long divisor = m;
        // Calculate sign of divisor i.e.,
        // sign will be negative only iff
        // either one of them is negative
        // otherwise it will be positive
        int sign = ((dividend < 0) || (divisor < 0)) ? -1 : 1;

        if ((n < 0) && (m < 0))
            sign = 1;
        // remove sign of operands
        dividend = abs(dividend);
        divisor = abs(divisor);

        // Initialize the quotient
        long long quotient = 0, temp = 0;

        // test down from the highest bit and
        // accumulate the tentative value for
        // valid bit
        for (int i = 31; i >= 0; --i)
        {

            if (temp + (divisor << i) <= dividend)
            {
                temp += divisor << i;
                quotient |= 1LL << i;
            }
        }

        return sign * quotient;
    }
};
// @lc code=end
