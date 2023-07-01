/*
 * @lc app=leetcode id=1192 lang=cpp
 *
 * [1192] Critical Connections in a Network
 */

// @lc code=start
class Solution
{
public:
    // did not get

    // Striver solution
    // dfs On+e time O2n array + On auxiliary recursion space

    void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<vector<int>> &adj, vector<vector<int>> &ans)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;

            if (!vis[it])
            {
                dfs(it, node, vis, tin, low, timer, adj, ans);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node]) //formula
                {
                    ans.push_back({node, it});
                }
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> tin(n, -1); //time of insertion
        vector<int> low(n, -1); // lowest time of insertion around all its adjacent nodes
        vector<int> vis(n, 0);

        vector<vector<int>> adj(n);
        for (vector v : connections) //convert to adjacency list
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        vector<vector<int>> ans;
        int timer = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, tin, low, timer, adj, ans);
            }
        }

        return ans;
    }
};
// @lc code=end
