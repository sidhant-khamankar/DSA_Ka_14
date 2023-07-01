/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution
{
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */

    int minMeetingRooms(vector<Interval> &intervals)
    {
        // Write your code here

        // Wrong ans, Neetcode solution Onlogn time sorting On space

        // Method 1 Two pointer
        if (intervals.size() == 0)
        {
            return 0;
        }

        int len = intervals.size();
        vector<int> startTime(len);
        vector<int> endTime(len);

        for (int i = 0; i < len; i++)
        {
            startTime[i] = intervals[i].start;
            endTime[i] = intervals[i].end;
        }

        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());

        int res = 0;
        int count = 0;
        int s = 0;
        int e = 0;

        while (s < len)
        {
            if (startTime[s] < endTime[e])
            {
                s++;
                count++;
            }
            else
            {
                e++;
                count--;
            }
            res = max(res, count);
        }

        return res;

        // Method 2 by using priority queue
        // sort intervals by start time
        // sort(intervals.begin(), intervals.end());

        // // min heap to track min end time of merged intervals
        // priority_queue<int, vector<int>, greater<int>> pq;
        // pq.push(intervals[0][1]);

        // for (int i = 1; i < intervals.size(); i++) {
        //     // compare curr start w/ earliest end time, if no overlap then pop
        //     if (intervals[i][0] >= pq.top()) {
        //         pq.pop();
        //     }
        //     // add new room (will replace/be same size if above was true)
        //     pq.push(intervals[i][1]);
        // }

        // return pq.size();
    }
};