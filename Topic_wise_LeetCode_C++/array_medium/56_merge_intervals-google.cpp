/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution //ONlogN time ON space
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        //Striver Optimized solution
        vector<vector<int>> mergedIntervals;
        if (intervals.size() == 0)
            return mergedIntervals;
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];

        for (auto it : intervals)
        {
            if (it[0] <= tempInterval[1])
                tempInterval[1] = max(it[1], tempInterval[1]);
            else
            {
                mergedIntervals.push_back(tempInterval);
                tempInterval = it;
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;

        //My solution TLE at last test case
        // sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
        //     if (a[0] != b[0])
        //         return a[0] < b[0];
        //     else
        //         return a[1] < b[1];
        // }); //sort according to first element first and then second
        // for (int i = 0; i + 1 < intervals.size(); i++)
        // {
        //     vector<int> first = intervals[i]; //first
        //     vector<int> second = intervals[i + 1]; //second
        //     if (second[0] <= first[1]) //second's first is less than first's second
        //     {
        //         int s = max(first[1], second[1]); //max of both's second element
        //         vector<int> v{first[0], s}; //merged
        //         intervals.insert(intervals.begin() + i + 2, v); //insert after merging two
        //         intervals.erase(intervals.begin() + i, intervals.begin() + i + 2); //delete merged
        //         i -= 1; //to start from merged
        //         // for (int i = 0; i < intervals.size(); i++)
        //         // {
        //         //     cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]"
        //         //          << ",";
        //         // }
        //         // cout << "\n";
        //     }
        // }
        // return intervals;
    }
};
// @lc code=end
