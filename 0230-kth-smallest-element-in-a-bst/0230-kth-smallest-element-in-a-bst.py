# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# iterate through whole tree and push elements to list
# sort list


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        elements = []

        def dfs(node):
            nonlocal elements
            elements.append(node.val)
            if node.left:
                dfs(node.left)
            if node.right:
                dfs(node.right)
        
        dfs(root)
        elements.sort()
        # print(elements)
        return elements[k-1]


