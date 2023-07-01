/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start

// did not get

//tech dose solution deadlock detection single resource instance distributed system
// deadlock detect cycle Ov+e time Ov space, other solution topological sort
// processed nodes are not considered cycle
class Solution
{
    bool isCyclic(vector<vector<int>> &adj, vector<int> &visited, int curr)
    {
        if (visited[curr] == 2) // processing
            return true;

        visited[curr] = 2; // processing
        for (int i = 0; i < adj[curr].size(); ++i)
            if (visited[adj[curr][i]] != 1) // skip processed
                if (isCyclic(adj, visited, adj[curr][i]))
                    return true;

        visited[curr] = 1;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<int>> adj(numCourses);
        //Make adjacency matrix (Directed graph)
        for (int i = 0; i < prerequisites.size(); ++i)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);

        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; ++i)
            if (visited[i] == 0) // unvisited
                if (isCyclic(adj, visited, i))
                    return false;

        return true;
    }
};
// @lc code=end
