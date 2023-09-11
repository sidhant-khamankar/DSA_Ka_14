# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# tricky fast and slow pointers
# My solution 
# class Solution:
#     def hasCycle(self, head: Optional[ListNode]) -> bool:
#         slow = head
#         if slow.next == None:
#             return False
#         fast = head.next.next
        
#         while slow and fast:
#             if slow == fast:
#                 return True
            
#             slow = slow.next
            
#             if fast.next == None:
#                 return False
            
#             fast = fast.next.next
        
#         return False

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


# neetcode solution like my solution
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        slow, fast = head, head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False

            
            
            