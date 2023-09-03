# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# did not get
# neetcode solution O(n) time

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev, curr = None, head

        while curr:
            # store next in temp
            temp = curr.next
            
            # link to previous
            curr.next = prev
            # make prev as curr
            prev = curr
            
            # move next
            curr = temp
        return prev
