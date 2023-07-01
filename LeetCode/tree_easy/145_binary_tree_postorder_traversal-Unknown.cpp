/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    // My solution On time On space
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postorder;
        iter(root, postorder);

        return postorder;
    }

    void recur(TreeNode *root, vector<int> &postorder)
    {
        if (root == NULL)
            return;
        recur(root->left, postorder);
        recur(root->right, postorder);
        postorder.push_back(root->val);
    }

    // Takeuforward solution O3n time O4n space
    // preorder, inorder, postorder in single traversal
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

    // one stack gfg
    // An iterative function to do postorder traversal
    // of a given binary tree
    void postOrderIterative(Node root)
    {
        Stack<Node> stack = new Stack<>();
        while (true)
        {
            while (root != null)
            {
                stack.push(root);
                stack.push(root);
                root = root.left;
            }

            // Check for empty stack
            if (stack.empty())
                return;
            root = stack.pop();

            if (!stack.empty() && stack.peek() == root)
                root = root.right;

            else
            {

                System.out.print(root.data + " ");
                root = null;
            }
        }
    }

    // two stacks techiedelight
    // Iterative function to perform postorder traversal on the tree
    void iter(TreeNode *root, vector<int> &postorder)
    {
        // create an empty stack and push the root node
        stack<TreeNode *> s;
        s.push(root);

        // create another stack to store postorder traversal
        stack<int> out;

        // loop till stack is empty
        while (!s.empty())
        {
            // pop a node from the stack and push the data into the output stack
            TreeNode *curr = s.top();
            s.pop();

            out.push(curr->val);

            // push the left and right child of the popped node into the stack
            if (curr->left)
            {
                s.push(curr->left);
            }

            if (curr->right)
            {
                s.push(curr->right);
            }
        }

        // print postorder traversal
        while (!out.empty())
        {
            postorder.push_back(out.top());
            out.pop();
        }
    }
};
// @lc code=end
