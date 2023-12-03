# Wrong logic, Neetcode solution
​
```
/*
* @lc app=leetcode id=572 lang=cpp
*
* [572] Subtree of Another Tree
*/
​
// @lc code=start
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution
{
public:
// wrong logic
// Neetcode solution
// Onumber of nodes in both trees time and space
bool sameTree(TreeNode *root, TreeNode *subRoot)
{
if (root == NULL && subRoot == NULL)
return true;
if (root != NULL && subRoot != NULL && root->val == subRoot->val)
return (sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right));
return false;
}
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
if (subRoot == NULL)
return true;
if (root == NULL)
return false;
​
if (sameTree(root, subRoot))
return true;
return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
}
};
// @lc code=end
​
```