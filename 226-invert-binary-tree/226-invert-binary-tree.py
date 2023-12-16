# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# My solution, Neetcode solution
# O(n) time O(n) recursion stack space
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        
        # swap the children
        root.left, root.right = root.right, root.left
        
        # make 2 recursive calls
        self.invertTree(root.left)
        self.invertTree(root.right)
        return root

    
# My solution, Leetcode solution

# ```
# /*
#  * @lc app=leetcode id=226 lang=cpp
#  *
#  * [226] Invert Binary Tree
#  */

# // @lc code=start
# /**
#  * Definition for a binary tree node.
#  * struct TreeNode {
#  *     int val;
#  *     TreeNode *left;
#  *     TreeNode *right;
#  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
#  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
#  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
#  * };
#  */
# /**
#  * Definition for a binary tree node.
#  * struct TreeNode {
#  *     int val;
#  *     TreeNode *left;
#  *     TreeNode *right;
#  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
#  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
#  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
#  * };
#  */
# class Solution
# {
# public:
#     // My solution On time On space in worst case On leaves at level
#     // Leetcode solution iterative
#     TreeNode *invertTree(TreeNode *root)
#     {
#         queue<TreeNode *> q;

#         if (root == NULL)
#         { // edge case
#             return root;
#         }
#         q.push(root);
#         while (!q.empty())
#         {
#             TreeNode *curr = q.front();  // get front of the queue
#             q.pop();                     // pop the front of queue
#             TreeNode *left = curr->left; // store left and right child pointers
#             TreeNode *right = curr->right;

#             curr->left = right; // swap left and right childs
#             curr->right = left;

#             if (left != NULL) // push only when left or right are not null
#                 q.push(left);
#             if (right != NULL)
#                 q.push(right);
#         }

#         return root;
#     }
# };
# // @lc code=end

# ```

# Lead coding by fraz solution, leetcode solution

# ```
#    // Lead Coding by fraz solution On time Oh function calls space where h is height of tree
#     // in worst case h can be n when tree is skewed
#     // Leetcode solution recursive
#     // void help(TreeNode *root)
#     // {
#     //     if (root == NULL)
#     //         return;
#     //     help(root->left);
#     //     help(root->right);
#     //     auto temp = root->left;
#     //     root->left = root->right;
#     //     root->right = temp;
#     // }
#     // TreeNode *invertTree(TreeNode *root)
#     // {
#     //     help(root);
#     //     return root;
#     // }
# ```
        
        