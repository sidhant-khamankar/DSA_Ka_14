/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution
{
    // Neetcode python solution On time On space
    // class Solution:
    // def insert(
    //     self, intervals: List[List[int]], newInterval: List[int]
    // ) -> List[List[int]]:
    //     res = []

    //     for i in range(len(intervals)):
    //         if newInterval[1] < intervals[i][0]:
    //             res.append(newInterval)
    //             return res + intervals[i:]
    //         elif newInterval[0] > intervals[i][1]:
    //             res.append(intervals[i])
    //         else:
    //             newInterval = [
    //                 min(newInterval[0], intervals[i][0]),
    //                 max(newInterval[1], intervals[i][1]),
    //             ]
    //     res.append(newInterval)
    //     return res
    // My solution On time On space
public:
    bool checkOverlap(vector<int> i, vector<int> newInterval)
    {
        if (newInterval[0] <= i[0] && newInterval[1] <= i[1] && i[0] <= newInterval[1])
            return true;
        else if (i[0] <= newInterval[0] && newInterval[1] <= i[1])
            return true;
        else if (i[0] <= newInterval[0] && i[1] <= newInterval[1] && newInterval[0] <= i[1])
            return true;
        else if (newInterval[0] <= i[0] && i[1] <= newInterval[1])
            return true;
        return false;
    }

    int getPos(int insert_pos, vector<int> i, vector<int> newInterval)
    {
        if (newInterval[1] < i[0])
            return insert_pos;

        else
            return insert_pos + 1;
    }
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        if (intervals.size() == 0)
            return {newInterval};
        int merged = 0;
        int insert_pos = 0;

        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size(); i++)
        {
            if (merged == 0 && checkOverlap(intervals[i], newInterval))
            {
                vector<int> merged_interval;

                merged_interval.push_back(min(intervals[i][0], newInterval[0]));
                merged_interval.push_back(max(intervals[i][1], newInterval[1]));
                ans.push_back(merged_interval);
                merged = 1;
            }
            else if (merged == 1 && checkOverlap(intervals[i], ans.back()))
            {
                vector<int> merge_adjacent;
                vector<int> last_interval = ans.back();

                merge_adjacent.push_back(min(intervals[i][0], last_interval[0]));
                merge_adjacent.push_back(max(intervals[i][1], last_interval[1]));
                ans.pop_back();
                ans.push_back(merge_adjacent);
            }
            else
            {
                ans.push_back(intervals[i]);
                if (intervals[i][0] < newInterval[0])
                {
                    insert_pos = i;
                }
            }
        }

        if (merged == 0)
        {
            insert_pos = getPos(insert_pos, intervals[insert_pos], newInterval);
            intervals.insert(intervals.begin() + insert_pos, newInterval);
            return intervals;
        }

        return ans;
    }
};
// @lc code=end
