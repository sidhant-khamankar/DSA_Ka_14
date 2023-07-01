/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    // my solution On time On space
    int recur(TreeNode *curr)
    {
        int h1 = 1, h2 = 1;
        if (curr->left != NULL)
            h1 += recur(curr->left);

        if (curr->right != NULL)
            h2 += recur(curr->right);
        return max(h1, h2);
    }
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return recur(root);
    }
};
// @lc code=end
