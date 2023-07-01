/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    // Takeuforward solution On time O1 space - Morris traversal
    // class Solution
    // {
    // public:
    //     vector<int> preorderTraversal(TreeNode *root)
    //     {
    //         vector<int> preorder;

    //         TreeNode *cur = root;
    //         while (cur != NULL)
    //         {
    //             if (cur->left == NULL)
    //             {
    //                 preorder.push_back(cur->val);
    //                 cur = cur->right;
    //             }
    //             else
    //             {
    //                 TreeNode *prev = cur->left;
    //                 while (prev->right != NULL && prev->right != cur)
    //                 {
    //                     prev = prev->right;
    //                 }

    //                 if (prev->right == NULL)
    //                 {
    //                     prev->right = cur;
    //                     preorder.push_back(cur->val);
    //                     cur = cur->left;
    //                 }
    //                 else
    //                 {
    //                     prev->right = NULL;
    //                     cur = cur->right;
    //                 }
    //             }
    //         }
    //         return preorder;
    //     }
    // };

    // Takeuforward solution O3n time O4n space
    // vector<int> postorderTraversal(TreeNode *root)
    // {
    //     stack<pair<TreeNode *, int>> st;
    //     st.push({root, 1});
    //     vector<int> pre, in, post;
    //     if (root == NULL)
    //         return post;

    //     while (!st.empty())
    //     {
    //         auto it = st.top();
    //         st.pop();

    //         // this is part of pre
    //         // increment 1 to 2
    //         // push the left side of the tree
    //         if (it.second == 1)
    //         {
    //             pre.push_back(it.first->val);
    //             it.second++;
    //             st.push(it);

    //             if (it.first->left != NULL)
    //             {
    //                 st.push({it.first->left, 1});
    //             }
    //         }

    //         // this is a part of in
    //         // increment 2 to 3
    //         // push right
    //         else if (it.second == 2)
    //         {
    //             in.push_back(it.first->val);
    //             it.second++;
    //             st.push(it);

    //             if (it.first->right != NULL)
    //             {
    //                 st.push({it.first->right, 1});
    //             }
    //         }
    //         // don't push it back again
    //         else
    //         {
    //             post.push_back(it.first->val);
    //         }
    //     }

    //     return post;
    // }

    // My solution
    // On time On space
    void recur(TreeNode *root, vector<int> &preorder)
    {
        if (root == NULL)
            return;
        preorder.push_back(root->val);
        recur(root->left, preorder);
        recur(root->right, preorder);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;
        iter(root, preorder);

        return preorder;
    }

    void iter(TreeNode *root, vector<int> &preorder)
    {
        TreeNode *curr = root;
        stack<TreeNode *> st;
        while (curr != nullptr || st.empty() == false)
        {
            if (curr != nullptr)
            {
                preorder.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = st.top();
                st.pop();
                curr = curr->right;
            }
        }
    }
};
// @lc code=end
