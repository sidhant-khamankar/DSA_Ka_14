/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 */

// @lc code=start
class Solution
{
public:
    // did not get
    // Aditya verma gfg solution
    // recursion exponential time
    // Function to get minimum
    // number of trials needed in worst
    // case with n eggs and k floors
    // int eggDrop(int n, int k)
    // {
    //     // If there are no floors,
    //     // then no trials needed.
    //     // OR if there is one floor,
    //     // one trial needed.
    //     if (k == 1 || k == 0)
    //         return k;

    //     // We need k trials for one
    //     // egg and k floors
    //     if (n == 1)
    //         return k;

    //     int min = INT_MAX, x, res;

    //     // Consider all droppings from
    //     // 1st floor to kth floor and
    //     // return the minimum of these
    //     // values plus 1.
    //     for (x = 1; x <= k; x++)
    //     {
    //         res = 1 + max(
    //                       eggDrop(n - 1, x - 1),
    //                       eggDrop(n, k - x));
    //         if (res < min)
    //             min = res;
    //     }

    //     return min;
    // }

    // bottom up dp memoization On*k^2 time On*k space
    // k floors, n eggs
    int solveEggDrop(int n, int k, vector<vector<int>> &memo)
    {

        if (memo[n][k] != -1)
        {
            return memo[n][k];
        }

        if (k == 1 || k == 0)
            return k;

        if (n == 1)
            return k;

        int minattemps = INT_MAX, x, res;

        // for (x = 1; x <= k; x++)
        // {
        //     res = 1 + max(
        //                   solveEggDrop(n - 1, x - 1, memo),
        //                   solveEggDrop(n, k - x, memo));
        //     if (res < min)
        //         min = res;
        // }
        int left = 1, right = k; // binary search leetcode solution
        while (left <= right)
        {
            int x = left + (right - left) / 2;
            int left_result = solveEggDrop(n - 1, x - 1, memo);               //breaks
            int right_result = solveEggDrop(n, k - x, memo);                  // does not breaks, move to higher floors
            minattemps = min(minattemps, 1 + max(left_result, right_result)); // leetcode solution graph
            if (left_result < right_result)
                left = x + 1;
            else
                right = x - 1;
        }

        memo[n][k] = minattemps;
        return minattemps;
    }
    int superEggDrop(int k, int n)
    {
        vector<vector<int>> memo(k + 1, vector<int>(n + 1, -1));
        return solveEggDrop(k, n, memo);
    }

    //did not get leetcode binary search solution Ok*nlogn time Ok*n space
    // class Solution
    // {
    // public
    //     int superEggDrop(int K, int N)
    //     {
    //         return dp(K, N);
    //     }

    //     Map<Integer, Integer> memo = new HashMap();
    // public
    //     int dp(int K, int N)
    //     {
    //         if (!memo.containsKey(N * 100 + K))
    //         {
    //             int ans;
    //             if (N == 0)
    //                 ans = 0;
    //             else if (K == 1)
    //                 ans = N;
    //             else
    //             {
    //                 int lo = 1, hi = N;
    //                 while (lo + 1 < hi)
    //                 {
    //                     int x = (lo + hi) / 2;
    //                     int t1 = dp(K - 1, x - 1);
    //                     int t2 = dp(K, N - x);

    //                     if (t1 < t2)
    //                         lo = x;
    //                     else if (t1 > t2)
    //                         hi = x;
    //                     else
    //                         lo = hi = x;
    //                 }

    //                 ans = 1 + Math.min(Math.max(dp(K - 1, lo - 1), dp(K, N - lo)),
    //                                    Math.max(dp(K - 1, hi - 1), dp(K, N - hi)));
    //             }

    //             memo.put(N * 100 + K, ans);
    //         }

    //         return memo.get(N * 100 + K);
    //     }
    // }

    //did not get leetcode solution Ok*n time On space
    //     class Solution
    //     {
    //     public
    //         int superEggDrop(int K, int N)
    //         {
    //             // Right now, dp[i] represents dp(1, i)
    //             int[] dp = new int[N + 1];
    //             for (int i = 0; i <= N; ++i)
    //                 dp[i] = i;

    //             for (int k = 2; k <= K; ++k)
    //             {
    //                 // Now, we will develop dp2[i] = dp(k, i)
    //                 int[] dp2 = new int[N + 1];
    //                 int x = 1;
    //                 for (int n = 1; n <= N; ++n)
    //                 {
    //                     // Let's find dp2[n] = dp(k, n)
    //                     // Increase our optimal x while we can make our answer better.
    //                     // Notice max(dp[x-1], dp2[n-x]) > max(dp[x], dp2[n-x-1])
    //                     // is simply max(T1(x-1), T2(x-1)) > max(T1(x), T2(x)).
    //                     while (x < n && Math.max(dp[x - 1], dp2[n - x]) > Math.max(dp[x], dp2[n - x - 1]))
    //                         x++;

    //                     // The final answer happens at this x.
    //                     dp2[n] = 1 + Math.max(dp[x - 1], dp2[n - x]);
    //                 }

    //                 dp = dp2;
    //             }

    //             return dp[N];
    //         }
    //     }

    //did not get leetcode maths solution Ok*logn time O1 space

    // class Solution
    // {
    // public
    //     int superEggDrop(int K, int N)
    //     {
    //         int lo = 1, hi = N;
    //         while (lo < hi)
    //         {
    //             int mi = (lo + hi) / 2;
    //             if (f(mi, K, N) < N)
    //                 lo = mi + 1;
    //             else
    //                 hi = mi;
    //         }

    //         return lo;
    //     }

    // public
    //     int f(int x, int K, int N)
    //     {
    //         int ans = 0, r = 1;
    //         for (int i = 1; i <= K; ++i)
    //         {
    //             r *= x - i + 1;
    //             r /= i;
    //             ans += r;
    //             if (ans >= N)
    //                 break;
    //         }
    //         return ans;
    //     }
    // }

    //leetcode discuss Oklogn
    // class Solution
    // {
    // public:
    //     int superEggDrop(int numEggs, int numFloors)
    //     {

    //         vector<int> dp(numEggs + 1, 0);

    //         int dropAttempts;

    //         for (dropAttempts = 0; dp[numEggs] < numFloors; ++dropAttempts)
    //         {
    //             for (int i = numEggs; i > 0; --i)
    //             {
    //                 dp[i] += dp[i - 1] + 1;
    //             }
    //         }
    //         return dropAttempts; // dp[1] == dropAttempts (they are interchangable)
    //     }
    // };
};
// @lc code=end
