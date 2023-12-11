# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


# My solution - breadth first traversal and considering last node at each level
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        
        last_node_at_level = []
        
        q = collections.deque()
        if root:
            q.append(root)
            
        while q:
            last_node_at_level.append(q[-1].val)
            for i in range(len(q)):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        
        return last_node_at_level
            
                
                
    