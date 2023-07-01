/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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

// aditya verma gfg solution
// On time On space
class Solution
{
public:
    // This function returns overall maximum path sum in 'res'
    // And returns max path sum going through root.
    int findMaxUtil(TreeNode *root, int &res)
    {
        //Base Case
        if (root == NULL)
            return 0;

        // l and r store maximum path sum going through left and
        // right child of root respectively
        int l = findMaxUtil(root->left, res);
        int r = findMaxUtil(root->right, res);

        // Max path for parent call of root. This path must
        // include at-most one child of root
        int max_single = max(max(l, r) + root->val, root->val); //or temp

        // Max Top represents the sum when the Node under
        // consideration is the root of the maxsum path and no
        // ancestors of root are there in max sum path
        int max_top = max(max_single, l + r + root->val); //or ans

        res = max(res, max_top); // Store the Maximum Result.

        return max_single; // or temp
    }

    // Returns maximum path sum in tree with given root
    int maxPathSum(TreeNode *root)
    {
        // Initialize result
        int res = INT_MIN;

        // Compute and return result
        findMaxUtil(root, res);
        return res;
    }
};
// @lc code=end
