/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution
{
public:
    // tech dose topological sort Ov+e time Ov+e space
    // class Solution
    // {
    //     //Graph coloring: 0->not visited...1->visited...2->visited & processed
    //     bool detectCycle_util(vector<vector<int>> &adj, vector<int> &visited, int v)
    //     {
    //         if (visited[v] == 1) // visited means processing
    //             return true;
    //         if (visited[v] == 2)
    //             return false;

    //         visited[v] = 1; //Mark current as visited
    //         for (int i = 0; i < adj[v].size(); ++i)
    //             if (detectCycle_util(adj, visited, adj[v][i]))
    //                 return true;

    //         visited[v] = 2; //Mark current node as processed
    //         return false;
    //     }

    //     //Cycle detection
    //     bool detectCycle(vector<vector<int>> &adj, int n)
    //     {
    //         vector<int> visited(n, 0);
    //         for (int i = 0; i < n; ++i)
    //             if (!visited[i])
    //                 if (detectCycle_util(adj, visited, i))
    //                     return true;
    //         return false;
    //     }

    //     //Topological sort
    //     void dfs(vector<vector<int>> &adj, int v, vector<bool> &visited, stack<int> &mystack)
    //     {
    //         visited[v] = true;
    //         for (int i = 0; i < adj[v].size(); ++i)
    //             if (!visited[adj[v][i]])
    //                 dfs(adj, adj[v][i], visited, mystack);

    //         mystack.push(v);
    //     }

    // public:
    //     vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    //     {
    //         int n = prerequisites.size();
    //         vector<vector<int>> adj(numCourses);
    //         //Make adjacecncy list
    //         for (int i = 0; i < n; ++i)
    //             adj[prerequisites[i][1]].push_back(prerequisites[i][0]);

    //         //Detect CYCLE...If present then return empty array
    //         vector<int> ans;
    //         if (detectCycle(adj, numCourses))
    //             return ans;

    //         //Find toposort and store it in stack
    //         stack<int> mystack;
    //         vector<bool> visited(numCourses, false);

    //         //Apply DFS and find topological sort
    //         for (int i = 0; i < numCourses; ++i)
    //             if (!visited[i])
    //                 dfs(adj, i, visited, mystack);

    //         while (!mystack.empty())
    //         {
    //             ans.push_back(mystack.top());
    //             mystack.pop();
    //         }
    //         return ans;
    //     }
    // };

    //Leetcode solution using toposort indegree Ov+e time Ov+e space
    // class Solution
    // {
    // public
    //     int[] findOrder(int numCourses, int[][] prerequisites)
    //     {

    //         boolean isPossible = true;
    //         Map<Integer, List<Integer>> adjList = new HashMap<Integer, List<Integer>>();
    //         int[] indegree = new int[numCourses];
    //         int[] topologicalOrder = new int[numCourses];

    //         // Create the adjacency list representation of the graph
    //         for (int i = 0; i < prerequisites.length; i++)
    //         {
    //             int dest = prerequisites[i][0];
    //             int src = prerequisites[i][1];
    //             List<Integer> lst = adjList.getOrDefault(src, new ArrayList<Integer>());
    //             lst.add(dest);
    //             adjList.put(src, lst);

    //             // Record in-degree of each vertex
    //             indegree[dest] += 1;
    //         }

    //         // Add all vertices with 0 in-degree to the queue
    //         Queue<Integer> q = new LinkedList<Integer>();
    //         for (int i = 0; i < numCourses; i++)
    //         {
    //             if (indegree[i] == 0)
    //             {
    //                 q.add(i);
    //             }
    //         }

    //         int i = 0;
    //         // Process until the Q becomes empty
    //         while (!q.isEmpty())
    //         {
    //             int node = q.remove();
    //             topologicalOrder[i++] = node;

    //             // Reduce the in-degree of each neighbor by 1
    //             if (adjList.containsKey(node))
    //             {
    //                 for (Integer neighbor : adjList.get(node))
    //                 {
    //                     indegree[neighbor]--;

    //                     // If in-degree of a neighbor becomes 0, add it to the Q
    //                     if (indegree[neighbor] == 0)
    //                     {
    //                         q.add(neighbor);
    //                     }
    //                 }
    //             }
    //         }

    //         // Check to see if topological sort is possible or not.
    //         if (i == numCourses)
    //         {
    //             return topologicalOrder;
    //         }

    //         return new int[0];
    //     }
    // }

    // My solution Ov+e time Ov space
    // small update to techdose course schedule,  leetcode solution - processed nodes are not considered cycle

    bool isCyclic(vector<vector<int>> &adj, vector<int> &visited, int curr, vector<int> &temp)
    {
        if (visited[curr] == 2) // processing
            return true;

        visited[curr] = 2; // processing
        for (int i = 0; i < adj[curr].size(); ++i)
            if (visited[adj[curr][i]] != 1) // skip processed
                if (isCyclic(adj, visited, adj[curr][i], temp))
                    return true;

        visited[curr] = 1;
        temp.push_back(curr);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        vector<int> temp;
        //Make adjacency matrix (Directed graph)
        for (int i = 0; i < prerequisites.size(); ++i)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);

        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; ++i)
            if (visited[i] == 0)
            { // unvisited
                if (isCyclic(adj, visited, i, temp))
                    return ans;
            }

        return temp;
    }
};
// @lc code=end
