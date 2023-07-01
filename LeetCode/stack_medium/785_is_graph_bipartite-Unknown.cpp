/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution
{
public:
    //did not get
    // Striver bfs solution ON+E time ON queue ON colour array
    bool bipartiteBfs(int src, vector<vector<int>> &graph, int color[])
    {
        queue<int> q;
        q.push(src);
        color[src] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : graph[node])
            {
                if (color[it] == -1)
                {
                    color[it] = 1 - color[node];
                    q.push(it);
                }
                else if (color[it] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        int color[n];
        memset(color, -1, sizeof color);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!bipartiteBfs(i, graph, color))
                {
                    return false;
                }
            }
        }
        return true;
    }

    // Striver dfs solution ON+E time ON auxiliary recursion stack ON colour array

    // bool bipartiteDfs(int node, vector<int> adj[], int color[])
    // {
    //     for (auto it : adj[node])
    //     {
    //         if (color[it] == -1)
    //         {
    //             color[it] = 1 - color[node];
    //             if (!bipartiteDfs(it, adj, color))
    //             {
    //                 return false;
    //             }
    //         }
    //         else if (color[it] == color[node])
    //             return false;
    //     }
    //     return true;
    // }
    // bool checkBipartite(vector<int> adj[], int n)
    // {
    //     int color[n];
    //     memset(color, -1, sizeof color);
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (color[i] == -1)
    //         {
    //             color[i] = 1;
    //             if (!bipartiteDfs(i, adj, color))
    //             {
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
};
// @lc code=end
