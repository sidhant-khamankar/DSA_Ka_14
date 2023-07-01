/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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

//The code mate gfg solution Oh time Oh space
// Iterator for BST
class bstit
{
private:
    // Stack to store the nodes
    // of BST
    stack<node *> q;

public:
    // Constructor for the class
    bstit(node *root)
    {
        // Initializing stack
        node *curr = root;
        while (curr != NULL)
            q.push(curr), curr = curr->left;
    }

    // Function to return
    // current element iterator
    // is pointing to
    node *curr()
    {
        return q.top();
    }

    // Function to iterate to next
    // element of BST
    void next()
    {
        node *curr = q.top()->right;
        q.pop();
        while (curr != NULL)
            q.push(curr), curr = curr->left;
    }

    // Function to check if
    // stack is empty
    bool isEnd()
    {
        return !(q.size());
    }
};
class BSTIterator
{
public:
    // My solution inorder traversal of bst On time On space
    // vector<int> lrr;
    // int i = 0;
    // void inorder(TreeNode *curr, vector<int> &lrr)
    // {
    //     if (curr == NULL)
    //         return;
    //     inorder(curr->left, lrr);
    //     lrr.push_back(curr->val);
    //     inorder(curr->right, lrr);
    // }
    // BSTIterator(TreeNode *root)
    // {
    //     inorder(root, lrr);
    // }

    // int next()
    // {
    //     if (i >= lrr.size())
    //         return -1;
    //     else
    //         return lrr[i++];
    // }

    // bool hasNext()
    // {
    //     if (i >= lrr.size())
    //         return false;
    //     else
    //         return true;
    // }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
