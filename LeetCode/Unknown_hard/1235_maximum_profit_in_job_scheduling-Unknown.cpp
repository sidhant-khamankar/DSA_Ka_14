/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
class Solution
{
public:
    //Code library solution binary search Onlogn time
    bool static sortByEndTime(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {

        vector<vector<int>> v;
        for (int i = 0; i < profit.size(); i++)
            v.push_back({startTime[i], endTime[i], profit[i]});

        sort(v.begin(), v.end(), sortByEndTime);

        int n = profit.size();
        int dp[n];
        dp[0] = v[0][2];
        for (int i = 1; i < n; i++)
        {
            int inc = v[i][2];
            int low = 0;
            int high = i - 1;
            int last = -1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;

                if (v[mid][1] <= v[i][0])
                {
                    last = mid;
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            if (last != -1)
                inc += dp[last];
            int exc = dp[i - 1];
            dp[i] = max(inc, exc);
        }

        return dp[n - 1];
    }

    // gfg solution linear search On^2 time
    // A job has start time, finish time and profit.
    // struct Job
    // {
    //     int start, finish, profit;
    // };

    // // A utility function that is used for sorting events
    // // according to finish time
    // bool jobComparataor(Job s1, Job s2)
    // {
    //     return (s1.finish < s2.finish);
    // }

    // // Find the latest job (in sorted array) that doesn't
    // // conflict with the job[i]
    // int latestNonConflict(Job arr[], int i)
    // {
    //     for (int j = i - 1; j >= 0; j--)
    //     {
    //         if (arr[j].finish <= arr[i].start)
    //             return j;
    //     }
    //     return -1;
    // }

    // // The main function that returns the maximum possible
    // // profit from given array of jobs
    // int findMaxProfit(Job arr[], int n)
    // {
    //     // Sort jobs according to finish time
    //     sort(arr, arr + n, jobComparataor);

    //     // Create an array to store solutions of subproblems.  table[i]
    //     // stores the profit for jobs till arr[i] (including arr[i])
    //     int *table = new int[n];
    //     table[0] = arr[0].profit;

    //     // Fill entries in M[] using recursive property
    //     for (int i = 1; i < n; i++)
    //     {
    //         // Find profit including the current job
    //         int inclProf = arr[i].profit;
    //         int l = latestNonConflict(arr, i);
    //         if (l != -1)
    //             inclProf += table[l];

    //         // Store maximum of including and excluding
    //         table[i] = max(inclProf, table[i - 1]);
    //     }

    //     // Store result and free dynamic memory allocated for table[]
    //     int result = table[n - 1];
    //     delete[] table;

    //     return result;
    // }

    // // Driver program
    // int main()
    // {
    //     Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    //     int n = sizeof(arr) / sizeof(arr[0]);
    //     cout << "The optimal profit is " << findMaxProfit(arr, n);
    //     return 0;
    // }

    //my solution 22/27 TLE

    // int recur(int ind, int oet, vector<vector<int>> &sep, vector<vector<int>> &dp)
    // {
    //     if (ind == sep.size())
    //         return 0;

    //     if (dp[ind][oet] != -1)
    //         return dp[ind][oet];

    //     // auto itr = sep.begin();
    //     // for (int i = 0; i < ind; i++)
    //     //     itr++;
    //     // vector<int> vsep = *itr;
    //     vector<int> vsep = sep[ind];
    //     if (vsep[1] >= oet)
    //     {
    //         return dp[ind][oet] = max(recur(ind + 1, oet, sep, dp), vsep[2] + recur(ind + 1, vsep[0], sep, dp));
    //     }
    //     else
    //     {
    //         return dp[ind][oet] = recur(ind + 1, oet, sep, dp);
    //     }
    // }
    // int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    // {
    //     vector<vector<int>> sep;

    //     int maxet = 0;
    //     for (int i = 0; i < startTime.size(); i++)
    //     {
    //         maxet = max(maxet, endTime[i]);
    //         sep.push_back({endTime[i], startTime[i], profit[i]});
    //     }

    //     sort(sep.begin(), sep.end());
    //     vector<vector<int>> dp(sep.size() + 1, vector<int>(maxet + 1, -1));
    //     return recur(0, 0, sep, dp);
    // }
};
// @lc code=end
