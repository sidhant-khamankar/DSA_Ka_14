/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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

// My solution recursive, leetcode threaded binary tree
// On time On space
class Solution
{
public:
    void recur(TreeNode *root, vector<int> &inorder)
    {
        if (root == nullptr)
            return;
        recur(root->left, inorder);
        inorder.push_back(root->val);
        recur(root->right, inorder);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;

        recur(root, inorder);

        return inorder;
    }

    // techie delight
    void iter(TreeNode *root, vector<int> &inorder)
    {
        // create an empty stack
        stack<TreeNode *> stack;

        // start from the root node (set current node to the root node)
        TreeNode *curr = root;

        // if the current node is null and the stack is also empty, we are done
        while (!stack.empty() || curr != nullptr)
        {
            // if the current node exists, push it into the stack (defer it)
            // and move to its left child
            if (curr != nullptr)
            {
                stack.push(curr);
                curr = curr->left;
            }
            else
            {
                // otherwise, if the current node is null, pop an element from the stack,
                // print it, and finally set the current node to its right child
                curr = stack.top();
                stack.pop();
                inorder.push_back(curr->val);

                curr = curr->right;
            }
        }
    }

    // Takeuforward solution On time O1 space Morris traversal - 1 line change for preorder
    // vector<int> inorderTraversal(TreeNode *root)
    // {
    //     vector<int> inorder;

    //     TreeNode *cur = root;
    //     while (cur != NULL)
    //     {
    //         if (cur->left == NULL)
    //         {
    //             inorder.push_back(cur->val);
    //             cur = cur->right;
    //         }
    //         else
    //         {
    //             TreeNode *prev = cur->left;
    //             while (prev->right != NULL && prev->right != cur)
    //             {
    //                 prev = prev->right;
    //             }

    //             if (prev->right == NULL)
    //             {
    //                 prev->right = cur;
    //                 cur = cur->left;
    //             }
    //             else
    //             {
    //                 prev->right = NULL;
    //                 inorder.push_back(cur->val);
    //                 cur = cur->right;
    //             }
    //         }
    //     }
    //     return inorder;
    // }

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
};
// @lc code=end
