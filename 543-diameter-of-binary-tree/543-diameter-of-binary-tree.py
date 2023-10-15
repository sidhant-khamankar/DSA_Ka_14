# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# couldn't solve

# neetcode solution dfs
# O(n) time
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        res = 0

        def dfs(root):
            nonlocal res

            if not root:
                return 0
            
            left = dfs(root.left)
            right = dfs(root.right)
            res = max(res, left + right)
            # diameter is number of lines between left and right nodes

            return 1 + max(left, right)
            # only max length of descending tree is considered and its length is sent back to its parent node for its calculation

        dfs(root)
        return res
