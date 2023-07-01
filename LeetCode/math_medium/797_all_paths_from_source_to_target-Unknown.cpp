/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution
{
public:
    // My solution Ov+e time Ov+e space
    // bfs
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        queue<pair<int, vector<int>>> q;
        q.push({0, {0}});
        vector<vector<int>> ans;

        while (!q.empty())
        {
            pair<int, vector<int>> p = q.front();
            q.pop();
            int node = p.first;
            vector<int> curr_path = p.second;
            if (node == graph.size() - 1)
            {
                ans.push_back(curr_path);
                continue;
            }
            for (int neighbour : graph[node])
            {
                curr_path.push_back(neighbour);
                q.push({neighbour, curr_path});
                curr_path.pop_back();
            }
        }

        return ans;
    }

    // Knowledge center solution
    // dfs Ov+e time Ov+e space

    // class Solution
    // {
    //     void dfs(vector<vector<int>> &graph, vector<vector<int>> &result, vector<int> &path, int u)
    //     {
    //         path.push_back(u);
    //         if (u == graph.size() - 1)
    //             result.push_back(path);
    //         else
    //             for (int v : graph[u])
    //                 dfs(graph, result, path, v);
    //         path.pop_back();
    //     }

    // public:
    //     vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    //     {
    //         vector<vector<int>> result;
    //         vector<int> path;
    //         dfs(graph, result, path, 0);
    //         return result;
    //     }
    // };
};
// @lc code=end
