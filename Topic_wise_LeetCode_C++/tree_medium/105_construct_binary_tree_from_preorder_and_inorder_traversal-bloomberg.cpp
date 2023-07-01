/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    //leetcode discuss On^2 time On space
    int preInd = 0;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return createTree(preorder, inorder, 0, inorder.size() - 1);
    }
    TreeNode *createTree(vector<int> &preorder, vector<int> &inorder, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }
        TreeNode *node = new TreeNode(preorder[preInd++]);
        int pos;
        for (int i = start; i <= end; i++)
        {
            if (inorder[i] == node->val)
            {
                pos = i;
                break;
            }
        }
        node->left = createTree(preorder, inorder, start, pos - 1);
        node->right = createTree(preorder, inorder, pos + 1, end);
        return node;
    }
    // code library gfg solution On time On space
    //     /* Recursive function to construct binary of size
    // len from Inorder traversal in[] and Preorder traversal
    // pre[]. Initial values of inStrt and inEnd should be
    // 0 and len -1. The function doesn't do any error
    // checking for cases where inorder and preorder
    // do not form a tree */
    //     TreeNode *buildTree(vector<int> &inorder, vector<int> &preorder, int inStrt, int inEnd, unordered_map<int, int> &mp)
    //     {
    //         static int preIndex = 0;

    //         if (inStrt > inEnd)
    //             return NULL;

    //         /* Pick current node from Preorder traversal using preIndex
    //     and increment preIndex */
    //         int curr = preorder[preIndex++];

    //         TreeNode *tNode = new TreeNode(curr);

    //         /* If this node has no children then return */
    //         if (inStrt == inEnd)
    //             return tNode;

    //         /* Else find the index of this node in Inorder traversal */
    //         int inIndex = mp[curr];

    //         /* Using index in Inorder traversal, construct left and
    //     right subtress */
    //         tNode->left = buildTree(inorder, preorder, inStrt, inIndex - 1, mp);
    //         tNode->right = buildTree(inorder, preorder, inIndex + 1, inEnd, mp);

    //         return tNode;
    //     }

    //     // This function mainly creates an unordered_map, then
    //     // calls buildTree()
    //     TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    //     {
    //         // Store indexes of all items so that we
    //         // we can quickly find later
    //         int len = inorder.size();
    //         unordered_map<int, int> mp;
    //         for (int i = 0; i < len; i++)
    //             mp[inorder[i]] = i;

    //         return buildTree(inorder, preorder, 0, len - 1, mp);
    //     }
};
// @lc code=end
