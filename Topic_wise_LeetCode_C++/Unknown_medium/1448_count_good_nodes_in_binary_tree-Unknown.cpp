/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
 */

// @lc code=start
/*
    Given binary tree, node is "good" if path from root has no nodes > X, return # of "good"
    Maintain greatest value seen so far on a path, if further node >= this max, "good" node
    Time: O(n)
    Space: O(n)
*/

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
    // My solution - priority queue, Wrong Answer 47/63 TCs
    // Neetcode solution On time Oh space
    int goodNodes(TreeNode *root)
    {
        int result = 0;
        dfs(root, root->val, result);
        return result;
    }

private:
    void dfs(TreeNode *root, int maxSoFar, int &result)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->val >= maxSoFar)
        {
            result++;
        }

        dfs(root->left, max(maxSoFar, root->val), result);
        dfs(root->right, max(maxSoFar, root->val), result);
    }
};
// @lc code=end
