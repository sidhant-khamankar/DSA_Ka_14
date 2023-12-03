# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Neetcode solution like my solution
# On time On space
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        # subRoot is NULL then return True
        if not t:
            return True
        
        # subRoot is not NULL but root is NULL so return False
        if not s:
            return False

        if self.sameTree(s, t):
            return True
        return self.isSubtree(s.left, t) or self.isSubtree(s.right, t)

    def sameTree(self, s, t):
        # both nodes are NULL then return True
        if not s and not t:
            return True
        
        # same value in both nodes then check left and right subtrees for equality
        if s and t and s.val == t.val:
            return self.sameTree(s.left, t.left) and self.sameTree(s.right, t.right)
        
        return False



# My solution On time On space
# class Solution:
#     def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        
#         def check_tree_equality(subtree_node, subroot_node):
#             if subtree_node == None or subroot_node == None:
#                 return subtree_node == subroot_node
            
#             if subtree_node.val == subroot_node.val:
#                 return (check_tree_equality(subtree_node.left, subroot_node.left) and 
#                         check_tree_equality(subtree_node.right, subroot_node.right))
            
#             return False
        
#         def dfs(node, subRoot):
#             if node == None:
#                 return False
            
#             if node and node.val == subRoot.val and check_tree_equality(node, subRoot):
#                 return True
#             else:
#                 return dfs(node.left, subRoot) or dfs(node.right, subRoot)
                
        
#         if subRoot == None:
#             return True
        
#         return dfs(root, subRoot)