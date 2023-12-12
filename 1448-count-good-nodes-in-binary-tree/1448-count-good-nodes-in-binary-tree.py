# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# neetcode solution like my solution
# On time On recursion space

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(node, maxVal):
            if not node:
                return 0

            res = 1 if node.val >= maxVal else 0
            maxVal = max(maxVal, node.val)
            res += dfs(node.left, maxVal)
            res += dfs(node.right, maxVal)
            return res

        return dfs(root, root.val)

# My solution On time On recursion space
# using non local variable
# class Solution:
#     def goodNodes(self, root: TreeNode) -> int:
#         ans = 0
#         def dfs(node, max_till_now):
#             nonlocal ans
#             if max_till_now <= node.val:
#                 ans += 1
            
#             if node.left:
#                 dfs(node.left, max(max_till_now, node.val))
#             if node.right:
#                 dfs(node.right, max(max_till_now, node.val))
        
#         dfs(root, root.val)
#         return ans
            