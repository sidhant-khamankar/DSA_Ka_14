# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# neetcode solution, using bst property
# On time On recursion space
# iterative solution but same complexity as recursive solution

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        stack = []
        curr = root

        # inorder
        while stack or curr:
            while curr:
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            k -= 1
            if k == 0:
                return curr.val
            
            curr = curr.right


# my solution Onlogn time On recursion space 
# ignored the fact that smaller element start from bottom left
# iterate through whole tree and push elements to list
# sort list


# class Solution:
#     def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
#         elements = []

#         def dfs(node):
#             nonlocal elements
#             elements.append(node.val)
#             if node.left:
#                 dfs(node.left)
#             if node.right:
#                 dfs(node.right)
        
#         dfs(root)
#         elements.sort()
#         return elements[k-1]


