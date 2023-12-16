* };
*/
class Solution
{
public:
// my solution On time On space
int recur(TreeNode *curr)
{
int h1 = 1, h2 = 1;
if (curr->left != NULL)
h1 += recur(curr->left);
​
if (curr->right != NULL)
h2 += recur(curr->right);
return max(h1, h2);
}
int maxDepth(TreeNode *root)
{
if (root == NULL)
return 0;
return recur(root);
}
};
// @lc code=end
​
```