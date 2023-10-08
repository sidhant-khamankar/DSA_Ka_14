# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        
        return self.recur(root)
    
    def recur(self, root):
        
        if not root:
            return root
        
        root.left, root.right = self.recur(root.right), self.recur(root.left)
        
        return root
        
        