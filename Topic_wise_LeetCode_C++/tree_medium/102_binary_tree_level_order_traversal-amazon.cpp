/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> vv;
        if (root == NULL)
            return vv;
        queue<pair<TreeNode *, int>> q;

        q.push({root, 0});
        vector<int> vr;
        vr.push_back(root->val);
        vv.push_back(vr);
        while (q.empty() == false)
        {
            TreeNode *t = q.front().first;
            int lev = q.front().second;

            q.pop();

            if ((lev + 1) < vv.size())
            {
                if (t->left != NULL)
                {
                    vv[lev + 1].push_back(t->left->val);
                    q.push({t->left, lev + 1});
                }
                if (t->right != NULL)
                {
                    vv[lev + 1].push_back(t->right->val);
                    q.push({t->right, lev + 1});
                }
            }

            else
            {
                vector<int> vl;
                if (t->left != NULL)
                {
                    vl.push_back(t->left->val);
                    q.push({t->left, lev + 1});
                }
                if (t->right != NULL)
                {
                    vl.push_back(t->right->val);
                    q.push({t->right, lev + 1});
                }
                if (vl.size() != 0)
                    vv.push_back(vl);
            }
        }

        return vv;
    }
};
// @lc code=end
