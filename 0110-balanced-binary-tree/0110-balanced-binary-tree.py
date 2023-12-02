# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# My solution On time On space
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        ans = True
        def height(node):
            nonlocal ans
            if node == None:
                return 0
            left_height = height(node.left)
            right_height = height(node.right)
            height_difference = abs(left_height - right_height)
            if height_difference > 1:
                ans = False
            return 1 + max(left_height, right_height)
        height(root)

        return ans
    
# neetcode solution similar to my solution
# On time 

# bottom up approach to ask each node from bottom if it is balanced or not. This way we visit each node at most one time. 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# class Solution:
#     def isBalanced(self, root: Optional[TreeNode]) -> bool:
#         def dfs(root):
#             if not root:
#                 return [True, 0]

#             left, right = dfs(root.left), dfs(root.right)
#             balanced = left[0] and right[0] and abs(left[1] - right[1]) <= 1
#             return [balanced, 1 + max(left[1], right[1])]

#         return dfs(root)[0]
