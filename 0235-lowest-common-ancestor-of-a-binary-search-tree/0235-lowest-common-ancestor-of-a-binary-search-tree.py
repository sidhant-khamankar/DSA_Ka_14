# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# My solution naive
# On time On space

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        path = []
        
        def dfs(node, search_node):
            if not node:
                return
            nonlocal path
            path.append(node)
            if node.val == search_node.val:
                return
            elif search_node.val < node.val:
                path.append(node)
                dfs(node.left, search_node)
            else:
                dfs(node.right, search_node)
        
        dfs(root, p)
        path_to_p = path
        path = []
        dfs(root, q)
        path_to_q = path
        
        i = 0
        j = 0
        while i < len(path_to_p) and j < len(path_to_q) and path_to_p[i] == path_to_q[j]:
            
            i += 1
            j += 1
            
        return path_to_p[i-1]
        