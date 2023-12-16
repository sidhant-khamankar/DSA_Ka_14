# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# did not get

# neetcode solution
# On^2 time On recursion space

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder or not inorder:
            return None

        root = TreeNode(preorder[0])
        # first element of preorder always contains root


        mid = inorder.index(preorder[0])
        # find root in inorder list and pass its left portion and corresponding same number of elements from preorder list for creating left subtree
        # similarly pass right portion of inorder list and corresponding leftover elements from preorder list for creating right subtree

        root.left = self.buildTree(preorder[1 : mid + 1], inorder[:mid])
        root.right = self.buildTree(preorder[mid + 1 :], inorder[mid + 1 :])
        return root

