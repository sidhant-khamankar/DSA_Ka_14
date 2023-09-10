# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# did not get
# neetcode solution
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0, head)
        left = dummy
        right = head
        
        # Advances right pointer so that the gap between right and left is n nodes apart
        while n > 0:
            right = right.next
            n -= 1
        
        # Move right to the end's next, maintaining the gap
        while right:
            left = left.next
            right = right.next

        # delete
        left.next = left.next.next
        return dummy.next
