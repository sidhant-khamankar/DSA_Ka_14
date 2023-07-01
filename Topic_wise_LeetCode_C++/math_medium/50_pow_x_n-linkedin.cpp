/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        //Striver Solution Ologn time
        double ans = 1.0;
        long long nn = n; //
        if (nn < 0)
            nn = -1 * nn;
        while (nn)
        {
            if (nn % 2)
            {
                ans = ans * x;
                nn = nn - 1;
            }
            else
            {
                x = x * x;
                nn = nn / 2;
            }
        }
        if (n < 0)
            ans = (double)(1.0) / (double)(ans);
        return ans;

        //My solution brute but TLE
        // double ans = 1;
        // if (n < 0)
        // {
        //     n = -n;
        //     for (int i = 0; i < n; i++)
        //     {
        //         ans *= (1 / x);
        //     }
        // }
        // else
        // {
        //     for (int i = 0; i < n; i++)
        //     {
        //         ans *= x;
        //     }
        // }
        // return ans;
    }
};
// @lc code=end
