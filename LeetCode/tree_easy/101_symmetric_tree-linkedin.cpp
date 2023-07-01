/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    // my solution On time On space
    bool isSymmetric(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        vector<vector<int>> vv;

        q.push({root, 0});

        vv.push_back({root->val});

        while (!q.empty())
        {
            TreeNode *curr = q.front().first;
            int lev = q.front().second;
            q.pop();

            vector<int> temp;

            if (curr->left != NULL)
            {
                q.push({curr->left, lev + 1});
                if (vv.size() > lev + 1)
                    vv[lev + 1].push_back(curr->left->val);
                else
                    temp.push_back(curr->left->val);
            }
            else
            {
                if (vv.size() > lev + 1)
                    vv[lev + 1].push_back(-101);
                else
                    temp.push_back(-101);
            }

            if (curr->right != NULL)
            {
                q.push({curr->right, lev + 1});
                if (vv.size() > lev + 1)
                    vv[lev + 1].push_back(curr->right->val);
                else
                    temp.push_back(curr->right->val);
            }
            else
            {
                if (vv.size() > lev + 1)
                    vv[lev + 1].push_back(-101);
                else
                    temp.push_back(-101);
            }

            vv.push_back(temp);
        }

        for (vector<int> v : vv)
        {
            int i = 0;
            int j = v.size() - 1;

            while (j >= i && v[i] == v[j])
            {
                i++;
                j--;
            }

            if (i <= j)
                return false;
        }

        return true;
    }
};
// @lc code=end
