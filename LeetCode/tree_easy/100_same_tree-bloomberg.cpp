/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// my solution On time On space
class Solution
{
public:
    // On time On space
    // Iterative method to find height of Binary Tree
    bool areIdentical(Node *root1, Node *root2)
    {
        // Return true if both trees are empty
        if (root1 == NULL && root2 == NULL)
            return true;

        // Return false if one is empty and other is not
        if (root1 == NULL)
            return false;
        if (root2 == NULL)
            return false;

        // Create an empty queues for simultaneous traversals
        queue<Node *> q1, q2;

        // Enqueue Roots of trees in respective queues
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty())
        {
            // Get front nodes and compare them
            Node *n1 = q1.front();
            Node *n2 = q2.front();

            if (n1->data != n2->data)
                return false;

            // Remove front nodes from queues
            q1.pop(), q2.pop();

            /* Enqueue left children of both nodes */
            if (n1->left && n2->left)
            {
                q1.push(n1->left);
                q2.push(n2->left);
            }

            // If one left child is empty and other is not
            else if (n1->left || n2->left)
                return false;

            // Right child code (Similar to left child code)
            if (n1->right && n2->right)
            {
                q1.push(n1->right);
                q2.push(n2->right);
            }
            else if (n1->right || n2->right)
                return false;
        }

        return true;
    }
    // bool isSameTree(TreeNode *p, TreeNode *q)
    // {
    //     if (p == NULL || q == NULL)
    //     {
    //         if (p != NULL)
    //             return false;
    //         else if (q != NULL)
    //             return false;
    //         else
    //             return true;
    //     }

    //     queue<pair<TreeNode *, TreeNode *>> que;
    //     if (p->val == q->val)
    //         que.push({p, q});
    //     else
    //         return false;

    //     while (!que.empty())
    //     {
    //         pair<TreeNode *, TreeNode *> pa = que.front();
    //         que.pop();

    //         if (pa.first->left != NULL || pa.second->left != NULL)
    //         {
    //             if (pa.first->left == NULL)
    //                 return false;
    //             else if (pa.second->left == NULL)
    //                 return false;
    //             else if (pa.first->left->val == pa.second->left->val)
    //                 que.push({pa.first->left, pa.second->left});
    //             else
    //                 return false;
    //         }
    //         if (pa.first->right != NULL || pa.second->right != NULL)
    //         {
    //             if (pa.first->right == NULL)
    //                 return false;
    //             else if (pa.second->right == NULL)
    //                 return false;
    //             else if (pa.first->right->val == pa.second->right->val)
    //                 que.push({pa.first->right, pa.second->right});
    //             else
    //                 return false;
    //         }
    //     }

    //     return true;
    // }
};
// @lc code=end
