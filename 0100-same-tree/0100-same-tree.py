# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# My soltuion On time On space
# class Solution:
#     def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
#         ans = True
#         def dfs(p, q):
#             nonlocal ans
#             if not ans:
#                 return
#             if p == None or q == None:
#                 ans = p == q
#                 return
            
#             if p.val != q.val:
#                 ans = False
            
#             dfs(p.left, q.left)
#             dfs(p.right, q.right)
        
#         dfs(p, q)
#         return ans
    
# neetcode solution similar to my solution
# On time On space
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q:
            return True
        if p and q and p.val == q.val:
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        else:
            return False
