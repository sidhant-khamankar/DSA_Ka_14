/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    // gfg solution On time On space
    /* A function that constructs Balanced
Binary Search Tree from a sorted array */
    TreeNode *sortedArrayToBST(vector<int> arr,
                               int start, int end)
    {
        /* Base Case */
        if (start > end)
            return NULL;

        /* Get the middle element and make it root */
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(arr[mid]);

        /* Recursively construct the left subtree 
    and make it left child of root */
        root->left = sortedArrayToBST(arr, start,
                                      mid - 1);

        /* Recursively construct the right subtree 
    and make it right child of root */
        root->right = sortedArrayToBST(arr, mid + 1, end);

        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
