/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution
{
public:
    // Mine Wrong ans
    // Neetcode Onlogn time O1 space greedy approach
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        // 7.00

        sort(intervals.begin(), intervals.end());

        int res = 0;
        int prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            // cout << intervals[i][0] << " " << intervals[i][1] << " " << checkOverlap(interval, intervals[i]) << endl;
            if (intervals[i][0] >= prevEnd)
            {
                prevEnd = intervals[i][1];
            }
            else
            {
                res++;
                prevEnd = min(prevEnd, intervals[i][1]);
            }
        }
        return res;
    }
};
// @lc code=end
