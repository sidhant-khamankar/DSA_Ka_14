/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution
{
public:
    //Techdose solution
    // same as my solution
    // push, pop Ologn time for heapify

    //###############################################################
    //###############################################################

    // My solution Onlogn space
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq(stones.begin(), stones.end()); // On build heap time
        // for (int ele : stones) //this would take Onlogn time as heapyfying after each insert
        // {
        //     pq.push(ele);
        // }

        while (pq.size() != 0 && pq.size() != 1) //Onlogn time
        {
            int firstHeavy = pq.top();
            pq.pop();
            int secondHeavy = pq.top();
            pq.pop();

            if (firstHeavy != secondHeavy)
            {
                pq.push(abs(firstHeavy - secondHeavy));
            }
        }

        if (pq.size() == 1)
            return pq.top();
        else
            return 0;
    }
};
// @lc code=end
