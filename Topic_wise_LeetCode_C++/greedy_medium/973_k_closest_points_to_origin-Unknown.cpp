/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution
{
    // My solution like Neetcode solution Oklogn time On space
    // heapify using min heap
    // Square root fails test case
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;

        for (vector<int> v : points)
        {
            pq.push({v[0] * v[0] + v[1] * v[1], v});
        }

        vector<vector<int>> ans;

        for (int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
// @lc code=end
