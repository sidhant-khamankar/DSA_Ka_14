# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# did not get
# neetcode solution
# O(n) time
class Solution:
    def reorderList(self, head: ListNode) -> None:
        # 1 2 3 4
        # find middle
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        # slow = 2
        
        
        # reverse second half
        second = slow.next
        # second = 3
        prev = slow.next = None
        # prev = None
        # 1 2 None
        
        # 3 4
        while second:
            tmp = second.next
            # tmp = 4
            second.next = prev
            # 3 None
            prev = second
            # prev = 3
            second = tmp
            # second = 4
        # 4 3
        # prev = 4
        
        # merge two halfs
        first, second = head, prev
        # first = 1 2 None
        # second = 4 3 None
        while second:
            tmp1, tmp2 = first.next, second.next
            # tmp1 = 2 | None
            # tmp2 = 3 | None
            first.next = second
            # first = 1 4 3 None | 2 3 None
            second.next = tmp1
            # second = 4 2 None | 3 None
            first, second = tmp1, tmp2
            # first = 2 | None
            # second = 3 | None
            
        # 1 4 2 3 None
