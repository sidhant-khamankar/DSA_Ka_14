/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
class Solution
{
public:
    // did not get, passing 49/84 test cases

    // Tech dose, Algorithms made easy solution On^2 time On space lis longest increasing subsequence

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {

        int n = envelopes.size();
        if (n == 0)
            return 0;

        sort(envelopes.begin(), envelopes.end()); //sorting in ascending order
        vector<int> dp(n + 1, 1);                 // dp[0] = 1 and others              // lis array
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j) //previous
            {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    //width and height of current should be greater than previous
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    // Leetcode discuss Onlogn time On space
    // int maxEnvelopes(vector<pair<int, int>> &es)
    // {
    //     sort(es.begin(), es.end(), [](pair<int, int> a, pair<int, int> b)
    //          { return a.first < b.first || (a.first == b.first && a.second > b.second); }); // sort by width ascending and if same then by height descending
    //     vector<int> dp;
    //     for (auto e : es)
    //     {
    //         auto iter = lower_bound(dp.begin(), dp.end(), e.second); //returns element iterator if found else next greater element's iterator
    //         if (iter == dp.end())
    //             dp.push_back(e.second);
    //         else if (e.second < *iter) // replace greater value with lesser
    //             *iter = e.second;
    //     }
    //     return dp.size();
    // }
};
// @lc code=end
