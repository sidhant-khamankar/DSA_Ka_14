/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int recur(TreeNode *curr, int &dia)
    {
        int h1 = 1, h2 = 1;
        if (curr->left != NULL)
            h1 = 1 + recur(curr->left, dia);

        if (curr->right != NULL)
            h2 = 1 + recur(curr->right, dia);

        if (dia < h1 + h2 - 2)
            dia = h1 + h2 - 2;

        return max(h1, h2);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int dia = 0;
        int height = recur(root, dia);

        return dia;
    }
};
// @lc code=end
