/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    // Code library gfg solution On time Oheight space
    // This function returns pointer to LCA of two given values n1 and n2.
    // This function assumes that n1 and n2 are present in Binary Tree
    TreeNode *lowestCommonAncestor(TreeNode *curr, TreeNode *p, TreeNode *q)
    {
        // Base case
        if (curr == NULL)
            return NULL;

        // If either n1 or n2 matches with curr's key, report
        // the presence by returning curr (Note that if a key is
        // ancestor of other, then the ancestor key becomes LCA
        if (curr == p || curr == q)
            return curr;

        // Look for keys in left and right subtrees
        TreeNode *left_lca = lowestCommonAncestor(curr->left, p, q);
        TreeNode *right_lca = lowestCommonAncestor(curr->right, p, q);

        // If both of the above calls return Non-NULL, then one key
        // is present in once subtree and other is present in other,
        // So this node is the LCA
        if (left_lca && right_lca)
            return curr;

        // Otherwise check if left subtree or right subtree is LCA
        return (left_lca != NULL) ? left_lca : right_lca;
    }
};
// @lc code=end
