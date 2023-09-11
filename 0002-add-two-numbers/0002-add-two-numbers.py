# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# My solution O(n) time O(n) space
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        dummy = ListNode(0, None)
        curr = dummy
        
        # 9 9 9 9 9 9 9
        # 9 9 9 9
        # -------------
        # 8 9 9 9 0 0 0 1
        
        while l1 and l2:
            addition = l1.val + l2.val + carry
            carry = 0
            if addition >= 10:
                carry = 1
                addition = addition%10
            curr.next = ListNode(addition, None)
            curr = curr.next
            l1 = l1.next
            l2 = l2.next
        
        while l1:
            addition = l1.val + carry
            carry = 0
            if addition >= 10:
                carry = 1
                addition = addition%10
            curr.next = ListNode(addition, None)
            curr = curr.next
            l1 = l1.next
        
        while l2:
            addition = l2.val + carry
            carry = 0
            if addition >= 10:
                carry = 1
                addition = addition%10
            curr.next = ListNode(addition, None)
            curr = curr.next
            l2 = l2.next
        
        if carry == 1:
            curr.next = ListNode(1, None)
            curr = curr.next
        
        return dummy.next
        
        
            
        