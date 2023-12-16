# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# My solution 
# O(n) time O(n) recursion stack space
# class Solution:
#     def maxDepth(self, root: Optional[TreeNode]) -> int:
#         return self.recur(root, 0)
    
#     def recur(self, root, maxDepth):
#         if not root:
#             return maxDepth
        
#         return max(self.recur(root.left, maxDepth + 1), self.recur(root.right, maxDepth + 1))

# neetcode solution 1
# RECURSIVE DFS
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0

        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

# neetcode solution 2
# ITERATIVE DFS using stack as popping once from end and appending to same end is possible
# explores left side of tree first so depth first search
# class Solution:
#     def maxDepth(self, root: TreeNode) -> int:
#         stack = [[root, 1]]
#         res = 0

#         while stack:
#             node, depth = stack.pop()

#             if node:
#                 res = max(res, depth)
#                 stack.append([node.left, depth + 1])
#                 stack.append([node.right, depth + 1])
#         return res


# neetcode solution 3
# BFS using deque as popping from front and appeding to last is possible
# uses for loop to traverse all nodes at a level so breadth first traversal
# class Solution:
#     def maxDepth(self, root: TreeNode) -> int:
#         q = deque()
#         if root:
#             q.append(root)

#         level = 0

#         while q:

#             for i in range(len(q)):
#                 node = q.popleft()
#                 if node.left:
#                     q.append(node.left)
#                 if node.right:
#                     q.append(node.right)
#             level += 1
#         return level

    

# Aditya verma 
# same as my solution just return 1+max(lh,rh);

# My solution

# ```
# /*
#  * @lc app=leetcode id=104 lang=cpp
#  *
#  * [104] Maximum Depth of Binary Tree
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
# class Solution
# {
# public:
#     // my solution On time On space
#     int recur(TreeNode *curr)
#     {
#         int h1 = 1, h2 = 1;
#         if (curr->left != NULL)
#             h1 += recur(curr->left);

#         if (curr->right != NULL)
#             h2 += recur(curr->right);
#         return max(h1, h2);
#     }
#     int maxDepth(TreeNode *root)
#     {
#         if (root == NULL)
#             return 0;
#         return recur(root);
#     }
# };
# // @lc code=end

# ```
        
        
        