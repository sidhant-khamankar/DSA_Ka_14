/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    // Mastering programming Leetcode discuss On^2 * 2^n time On2^n*n space
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return vector<TreeNode *>();
        return genTrees(1, n);
    }
    vector<TreeNode *> genTrees(int start, int end)
    {
        vector<TreeNode *> res;
        if (start > end)
        {
            res.push_back(NULL);
            return res;
        }
        else if (start == end)
        {
            res.push_back(new TreeNode(start));
            return res;
        }
        vector<TreeNode *> left, right;
        for (int i = start; i <= end; i++)
        {
            left = genTrees(start, i - 1);
            right = genTrees(i + 1, end);
            for (auto lnode : left)
            {
                for (auto rnode : right)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    // Tech dose solution catalan numbers to count
    // class Solution
    // {
    //     int catalan_Number(int n)
    //     {
    //         int catalan[n + 1];
    //         catalan[0] = catalan[1] = 1;

    //         for (int i = 2; i <= n; ++i)
    //         {
    //             catalan[i] = 0;
    //             for (int j = 0; j < i; ++j)
    //                 catalan[i] += catalan[j] * catalan[i - j - 1];
    //         }
    //         return catalan[n];
    //     }

    // public:
    //     int numTrees(int n)
    //     {
    //         return catalan_Number(n);
    //     }
    // };
};
// @lc code=end
