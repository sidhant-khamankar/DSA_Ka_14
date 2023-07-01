/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    // Code library solution Ok+h time Oh space
    int ans;
    void solve(TreeNode *root, int k, int &idx)
    {
        if (root == NULL)
            return;

        solve(root->left, k, idx);
        if (k == idx)
        {
            ans = root->val;
            idx++;
            return;
        }
        else
            idx++;

        solve(root->right, k, idx);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int idx = 1;
        ans = -1;
        solve(root, k, idx);
        return ans;
    }
    // My solution inorder traversal On time On space
    // void inorder(TreeNode *curr, vector<int> &v)
    // {
    //     if (curr == NULL)
    //         return;
    //     inorder(curr->left, v);
    //     v.push_back(curr->val);
    //     inorder(curr->right, v);
    // }
    // int kthSmallest(TreeNode *root, int k)
    // {
    //     //Your code here
    //     vector<int> v;
    //     inorder(root, v);
    //     return v[k - 1];
    // }
};
// @lc code=end
