/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    // Code library solution dfs OV+E time OV space
    void dfs(Node *node, Node *copy, vector<Node *> &vis)
    {
        vis[copy->val] = copy;
        for (auto x : node->neighbors)
        {
            if (vis[x->val] == NULL)
            {
                Node *newNode = new Node(x->val);
                (copy->neighbors).push_back(newNode);
                dfs(x, newNode, vis);
            }
            else
            {
                (copy->neighbors).push_back(vis[x->val]);
            }
        }
    }
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        vector<Node *> vis(1000, NULL);
        Node *copy = new Node(node->val);

        dfs(node, copy, vis);
        return copy;
    }
    // My solution OE time OV space
    // bool static comp(Node *a, Node *b)
    // {
    //     if (a->val < b->val)
    //         return true;
    //     return false;
    // }
    // Node *cloneGraph(Node *node)
    // {
    //     if (node == NULL)
    //         return node;
    //     vector<Node *> original_nodes;
    //     unordered_map<int, int> visited;
    //     queue<Node *> q;
    //     q.push(node);

    //     while (q.empty() == false)
    //     {
    //         Node *curr = q.front();
    //         q.pop();

    //         if (visited[curr->val - 1] != 1)
    //         {
    //             original_nodes.push_back(curr);
    //             for (Node *iter : curr->neighbors)
    //             {
    //                 q.push(iter);
    //             }
    //             visited[curr->val - 1] = 1;
    //         }
    //     }

    //     sort(original_nodes.begin(), original_nodes.end(), comp);
    //     vector<Node *> dupNodes;
    //     for (Node *curr : original_nodes)
    //     {
    //         dupNodes.push_back(new Node(curr->val));
    //     }
    //     for (Node *curr : original_nodes)
    //     {
    //         for (Node *neighbor : curr->neighbors)
    //         {
    //             dupNodes[curr->val - 1]->neighbors.push_back(dupNodes[neighbor->val - 1]);
    //         }
    //     }

    //     return dupNodes[0];
    // }
};
// @lc code=end
