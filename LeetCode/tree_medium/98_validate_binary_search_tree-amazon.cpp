/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    //apna college gfg solution On time On space
    /* A binary tree node has data, pointer to
   left child and a pointer to right child */
    struct Node
    {
        int data;
        struct Node *left, *right;
    };

    // Returns true if given tree is BST.
    bool isBST(Node *root, Node *l = NULL, Node *r = NULL)
    {
        // Base condition
        if (root == NULL)
            return true;

        // if left node exist then check it has
        // correct data or not i.e. left node's data
        // should be less than root's data
        if (l != NULL and root->data <= l->data)
            return false;

        // if right node exist then check it has
        // correct data or not i.e. right node's data
        // should be greater than root's data
        if (r != NULL and root->data >= r->data)
            return false;

        // check recursively for every node.
        return isBST(root->left, l, root) and
               isBST(root->right, root, r);
    }
    // my solution On time On space
    // void inorder(TreeNode *curr, vector<int> &v)
    // {
    //     if (curr == NULL)
    //         return;

    //     inorder(curr->left, v);
    //     v.push_back(curr->val);
    //     inorder(curr->right, v);
    // }
    // bool isValidBST(TreeNode *root)
    // {
    //     vector<int> v;
    //     inorder(root, v);

    //     for (int i = 0; i < v.size() - 1; i++)
    //         if (v[i] >= v[i + 1])
    //             return false;

    //     return true;
    // }
};
// @lc code=end
