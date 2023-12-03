# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        ans = True
        def dfs(p, q):
            nonlocal ans
            if not ans:
                return
            if p == None or q == None:
                ans = p == q
                return
            
            if p.val != q.val:
                ans = False
            
            dfs(p.left, q.left)
            dfs(p.right, q.right)
        
        dfs(p, q)
        return ans