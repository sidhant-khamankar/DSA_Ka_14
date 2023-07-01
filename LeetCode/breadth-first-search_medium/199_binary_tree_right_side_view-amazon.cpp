/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    //Striver solution On time OH space (answer data structure space isn't counted)
    // Reverse preorder like Root Right Left

    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if (root == NULL)
            return;
        if (res.size() == level)
            res.push_back(root->val);
        recursion(root->right, level + 1, res);
        recursion(root->left, level + 1, res);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }

    // My solution On time On/2 leaf nodes worst space
    // vector<int> rightSideView(TreeNode *root)
    // {
    //     vector<int> ans;
    //     queue<TreeNode *> q;
    //     if (root == NULL)
    //         return ans;
    //     q.push(root);
    //     while (!q.empty())
    //     {
    //         int no_of_nodes_at_level = q.size();
    //         for (int i = 1; i <= no_of_nodes_at_level; i++)
    //         {
    //             TreeNode *curr_node = q.front();
    //             if (i == no_of_nodes_at_level)
    //             {
    //                 ans.push_back(curr_node->val);
    //             }
    //             if (curr_node->left != NULL)
    //                 q.push(curr_node->left);
    //             if (curr_node->right != NULL)
    //                 q.push(curr_node->right);
    //             q.pop();
    //         }
    //     }
    //     return ans;
    // }
};
// @lc code=end
