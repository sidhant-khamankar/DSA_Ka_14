/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    int recur(TreeNode *curr, int &balanced)
    {
        if (curr == NULL)
            return -1;
        int lh = 1 + recur(curr->left, balanced);
        int rh = 1 + recur(curr->right, balanced);

        if (abs(lh - rh) > 1)
            balanced = 0;

        return max(lh, rh);
    }
    bool isBalanced(TreeNode *root)
    {
        int balanced = 1;
        int h = recur(root, balanced);

        if (balanced)
            return true;
        else
            return false;
    }
};
// @lc code=end
