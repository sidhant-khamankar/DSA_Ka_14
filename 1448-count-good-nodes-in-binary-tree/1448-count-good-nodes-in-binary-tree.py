# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# My solution On time On recursion space
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        ans = 0
        def dfs(node, max_till_now):
            nonlocal ans
            if max_till_now <= node.val:
                ans += 1
            
            if node.left:
                dfs(node.left, max(max_till_now, node.val))
            if node.right:
                dfs(node.right, max(max_till_now, node.val))
        
        dfs(root, root.val)
        return ans
            