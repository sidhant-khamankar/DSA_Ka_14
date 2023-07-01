/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
 */

// @lc code=start
class Solution
{
public:
    // Did not get
    // Fraz solution
    // Recursion - TLE
    // DP On*underroot(n) time On space
    // N's two factors at a time can be calculated upto <=underroot(n) i.e. i, N/i;
    int dp[1001];
    int help(int N)
    {
        if (N == 1)
            return 0;
        if (dp[N] != -1)
            return dp[N];
        else
        {
            for (int i = 1; i * i <= N; i++)
            {
                if (N % i == 0)
                {
                    if (help(N - 1) == 0)
                        return dp[N] = 1;
                    if ((i != 1) && help(N - (N / i)) == 0)
                        return dp[N] = 1;
                }
            }
            return dp[N] = 0;
        }
    }

    bool divisorGame(int n)
    {
        memset(dp, -1, sizeof dp);
        return help(n);

        // Optimal - O1 time O1 space
        // Reason: Odd numbers have odd factors and odd - odd = even and when N is even Player getting even N wins i.e Bob as Alice makes first move
        // return N % 2 == 0;
    }
};
// @lc code=end
