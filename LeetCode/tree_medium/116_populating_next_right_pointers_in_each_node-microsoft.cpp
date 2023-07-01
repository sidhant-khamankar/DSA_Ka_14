/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    //jayati tiwari java solution On time On space
    Node *connect(Node *root)
    {
        if (root == null)
            return root;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        q.add(null);

        while (!q.isEmpty())
        {
            Node curr = q.poll();
            if (curr == null && q.isEmpty())
            {
                return root;
            }
            else if (curr == null)
            {
                q.add(null);
            }
            else
            {
                curr.next = q.peek();
                if (curr.left != null)
                    q.add(curr.left);
                if (curr.right != null)
                    q.add(curr.right);
            }
        }
    }

    // My solution On time On space
    // Node *connect(Node *root)
    // {

    //     if (root == NULL)
    //         return root;
    //     queue<pair<Node *, int>> q;
    //     vector<vector<Node *>> vv;

    //     q.push({root, 0});
    //     vv.push_back({root});

    //     while (!q.empty())
    //     {
    //         Node *curr = q.front().first;
    //         int lev = q.front().second;
    //         q.pop();

    //         vector<Node *> temp;

    //         if (curr->left != NULL)
    //         {
    //             q.push({curr->left, lev + 1});
    //             if (vv.size() > lev + 1)
    //                 vv[lev + 1].push_back(curr->left);
    //             else
    //                 temp.push_back(curr->left);
    //         }

    //         if (curr->right != NULL)
    //         {
    //             q.push({curr->right, lev + 1});
    //             if (vv.size() > lev + 1)
    //                 vv[lev + 1].push_back(curr->right);
    //             else
    //                 temp.push_back(curr->right);
    //         }

    //         if (temp.size() != 0)
    //             vv.push_back(temp);
    //     }

    //     // cout << vv.size() << endl;
    //     for (vector<Node *> v : vv)
    //     {

    //         for (int i = 0; i < v.size() - 1; i++)
    //         {
    //             // cout << v[i]->val << " ";
    //             v[i]->next = v[i + 1];
    //             // cout << v[i]->next->val << " ";
    //         }
    //         // cout << v[i]->val << endl;
    //         // cout << endl;
    //     }

    //     return root;
    // }
};
// @lc code=end
