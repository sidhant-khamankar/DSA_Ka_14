/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
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
    // did not get
    // Leetcode solution, Neetcode solution 2^n time 2^n space
    unordered_map<int, vector<TreeNode *>> memo;
    vector<TreeNode *> allPossibleFBT(int N)
    {
        if (memo.find(N) == memo.end())
        {
            vector<TreeNode *> ans;
            if (N == 1)
            {
                ans.push_back(new TreeNode(0));
            }
            else if (N % 2 == 1) // odd nodes
            {
                for (int x = 0; x < N; ++x) // left nodes
                {
                    int y = N - 1 - x;                            // right nodes
                    for (TreeNode *left : allPossibleFBT(x))      // trees formed from left
                        for (TreeNode *right : allPossibleFBT(y)) // trees formed from right
                        {
                            TreeNode *bns = new TreeNode(0);
                            bns->left = left;
                            bns->right = right;
                            ans.push_back(bns);
                        }
                }
            }
            memo[N] = ans;
        }

        return memo[N];
    }
};
// @lc code=end
