/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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

//my solution On^2 time On space
// time can be On if unordered map is used for searching inorder array
class Solution
{
public:
    TreeNode *recur(vector<int> &inorder, vector<int> &postorder, int s, int e, int &postInd)
    {

        if (s > e)
            return NULL;

        // cout << postorder[postInd] << " " << s << " " << e << endl;
        TreeNode *tNode = new TreeNode(postorder[postInd--]);

        if (s == e)
            return tNode;

        int pos;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == tNode->val)
                pos = i;
        }

        tNode->right = recur(inorder, postorder, pos + 1, e, postInd);
        tNode->left = recur(inorder, postorder, s, pos - 1, postInd);

        return tNode;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int postInd = postorder.size() - 1;
        return recur(inorder, postorder, 0, inorder.size() - 1, postInd);
    }
};
// @lc code=end
