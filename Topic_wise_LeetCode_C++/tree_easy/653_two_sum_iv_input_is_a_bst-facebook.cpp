/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
class Solution
{
public:
//Kashish Mehndiratta solution On time Oheight space
#include <bits/stdc++.h>
    using namespace std;

    struct Node
    {
        int data;
        Node *left, *right;
    };

    void pushElements(Node *root, stack<Node *> &s, bool direction)
    {
        if (direction)
        {
            while (root)
            {
                s.push(root);
                root = root->left;
            }
            return;
        }
        while (root)
        {
            s.push(root);
            root = root->right;
        }
    }

    int isPairPresent(struct Node *root, int target)
    {
        if (!root)
            return 0;
        stack<Node *> s1, s2;
        int x, y;
        Node *temp;
        pushElements(root, s1, true);
        pushElements(root, s2, false);
        while (!s1.empty() && !s2.empty() && s1.top()->data < s2.top()->data)
        {
            x = s1.top()->data;
            y = s2.top()->data;
            if (x + y == target)
                return 1;
            if (x + y < target)
            {
                temp = s1.top();
                s1.pop();
                pushElements(temp->right, s1, true);
            }
            else
            {
                temp = s2.top();
                s2.pop();
                pushElements(temp->left, s2, false);
            }
        }
        return 0;
    }
    // My solution On*height time On space
    // bool findt(TreeNode *root, int k, TreeNode *old, TreeNode *curr)
    // {
    //     if (old == NULL)
    //     {
    //         queue<TreeNode *> q;

    //         q.push(root);
    //         while (q.empty() == false)
    //         {
    //             TreeNode *first = q.front();
    //             q.pop();

    //             if (findt(root, k - first->val, first, root))
    //                 return true;

    //             if (first->left != NULL)
    //                 q.push(first->left);
    //             if (first->right != NULL)
    //                 q.push(first->right);
    //         }
    //     }
    //     else
    //     {
    //         if (curr == NULL)
    //             return false;
    //         else if (curr->val == k && curr != old)
    //             return true;

    //         if (curr->val > k)
    //             return findt(root, k, old, curr->left);
    //         else if (curr->val < k)
    //             return findt(root, k, old, curr->right);
    //     }
    //     return false;
    // }
    // bool findTarget(TreeNode *root, int k)
    // {
    //     return findt(root, k, NULL, NULL);
    // }
};
// @lc code=end
