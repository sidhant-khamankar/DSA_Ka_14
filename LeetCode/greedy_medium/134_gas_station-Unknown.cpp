/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution
{
public:
    //KnowledgeCenter solution On time O1 space
    // Tricky, start from next position after negative delta as it would again become negative upto last point from start +1
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int total_surplus = 0;
        int surplus = 0;
        int S = 0;

        for (int i = 0; i < n; ++i)
        {
            total_surplus += gas[i] - cost[i];
            surplus += gas[i] - cost[i];
            if (surplus < 0)
            {
                surplus = 0;
                S = i + 1;
            }
        }
        return (total_surplus < 0) ? -1 : S;
    }
    //My solution TLE On^2 time O1 space
    // int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    // {
    //     int n = gas.size();
    //     int i, j;
    //     for (i = 0; i < n; i++)
    //     {
    //         int tank = gas[i];
    //         int curr_cost;
    //         for (j = (i + 1) % n; j != i; j = (++j) % n)
    //         {
    //             curr_cost = j == 0 ? cost[n - 1] : cost[j - 1];
    //             // cout<<"curr_cost: "<<curr_cost<<endl;
    //             if (tank - curr_cost >= 0)
    //             {
    //                 tank = tank - curr_cost + gas[j];
    //                 // cout<<"tank: "<<i<<" "<<j<<endl;
    //             }
    //             else
    //             {
    //                 // cout<<"break: "<<i<<" "<<j<<endl;
    //                 break;
    //             }
    //         }
    //         curr_cost = j == 0 ? cost[n - 1] : cost[j - 1];
    //         if (i == j && tank - curr_cost >= 0)
    //         {
    //             return i;
    //         }
    //     }

    //     return -1;
    // }
};
// @lc code=end
