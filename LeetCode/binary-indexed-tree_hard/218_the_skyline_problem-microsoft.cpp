/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class Solution
{
public:
    // did not get

    // Leetcode solution
    // The idea is to do line sweep and just process the buildings only at the start and end points.The key is to use a priority queue to save all the buildings that are still "alive".The queue is sorted by its height and end time(the larger height first and if equal height, the one with a bigger end time first).For each iteration, we first find the current process time, which is either the next new building start time or the end time of the top entry of the live queue.If the new building start time is larger than the top one end time, then process the one in the queue first(pop them until it is empty or find the first one that ends after the new building);
    // otherswise, if the new building starts before the top one ends, then process the new building(just put them in the queue).After processing, output it to the resulting vector if the height changes.Complexity is the worst case O(NlogN)

    // Dry runned Ex 1

    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> res;
        int cur = 0, cur_X, cur_H = -1, len = buildings.size();
        priority_queue<pair<int, int>> liveBlg; // first: height, second, end time
        while (cur < len || !liveBlg.empty())
        {                                                                       // if either some new building is not processed or live building queue is not empty
            cur_X = liveBlg.empty() ? buildings[cur][0] : liveBlg.top().second; // next timing point to process

            if (cur >= len || buildings[cur][0] > cur_X)
            { //first check if the current tallest building will end before the next timing point
                // pop up the processed buildings, i.e. those  have height no larger than cur_H and end before the top one
                while (!liveBlg.empty() && (liveBlg.top().second <= cur_X))
                    liveBlg.pop();
            }
            else
            { // if the next new building starts before the top one ends, process the new building in the vector
                cur_X = buildings[cur][0];
                while (cur < len && buildings[cur][0] == cur_X) // go through all the new buildings that starts at the same point
                {                                               // just push them in the queue
                    liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }
            cur_H = liveBlg.empty() ? 0 : liveBlg.top().first; // outut the top one
            if (res.empty() || (res.back()[1] != cur_H))
                res.push_back({cur_X, cur_H});
        }
        return res;
    }
};
// @lc code=end
