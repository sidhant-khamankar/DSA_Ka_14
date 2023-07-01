/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
//Apna college gfg solution inplace On time O1 space

struct Node
{
    int key;
    Node *left, *right;
};
/* utility that allocates a new Node
   with the given key  */
Node *newNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}

// Function to convert binary tree into
// linked list by altering the right node
// and making left node point to NULL
void flatten(struct Node *root)
{
    // base condition- return if root is NULL
    // or if it is a leaf node
    if (root == NULL || root->left == NULL &&
                            root->right == NULL)
    {
        return;
    }

    // if root->left exists then we have
    // to make it root->right
    if (root->left != NULL)
    {

        // move left recursively
        flatten(root->left);

        // store the node root->right
        struct Node *tmpRight = root->right;
        root->right = root->left;
        root->left = NULL;

        // find the position to insert
        // the stored value
        struct Node *t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }

        // insert the stored value
        t->right = tmpRight;
    }

    // now call the same function
    // for root->right
    flatten(root->right);
}

// To find the inorder traversal
void inorder(struct Node *root)
{
    // base condition
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// My solution On time On space
// class Solution
// {
// public:
//     void preorder(TreeNode *root, vector<int> &pre)
//     {
//         if (root == NULL)
//             return;
//         pre.push_back(root->val);
//         preorder(root->left, pre);
//         preorder(root->right, pre);
//     }
//     void flatten(TreeNode *root)
//     {

//         if (root == NULL)
//             return;
//         vector<int> pre;

//         preorder(root, pre);

//         TreeNode *droot = new TreeNode();

//         TreeNode *nroot = new TreeNode();
//         nroot->right = droot;

//         for (int i = 0; i < pre.size(); i++)
//         {
//             TreeNode *ri = new TreeNode(pre[i]);
//             droot->right = ri;

//             droot = droot->right;
//         }

//         root->right = nroot->right->right->right;
//         root->left = NULL;
//     }
// };
// @lc code=end
