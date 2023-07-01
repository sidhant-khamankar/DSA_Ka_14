/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution
{
public:
    // Nick white solution On time O1 space
    // int fib(int N)
    // {
    //     int a = 0;
    //     int b = 1;
    //     int sum = a + b;
    //     while (N > 1)
    //     {
    //         sum = a + b;
    //         a = b;
    //         b = sum;
    //         N--;
    //     }
    //     return sum;
    // }
    int recur(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        return recur(n - 1) + recur(n - 2);
    }
    int fib(int n)
    {
        // My solution, Nick white solution O2^n time O2^n space
        return recur(n);
    }
};
// @lc code=end
