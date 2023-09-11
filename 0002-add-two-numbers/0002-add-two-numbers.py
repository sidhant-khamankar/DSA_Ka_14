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
    
    
# neetcode solution like my solution
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# class Solution:
#     def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
#         dummy = ListNode()
#         cur = dummy

#         carry = 0
#         while l1 or l2 or carry:
#             v1 = l1.val if l1 else 0
#             v2 = l2.val if l2 else 0

#             # new digit
#             val = v1 + v2 + carry
#             carry = val // 10
#             val = val % 10
#             cur.next = ListNode(val)

#             # update ptrs
#             cur = cur.next
#             l1 = l1.next if l1 else None
#             l2 = l2.next if l2 else None

#         return dummy.next

        
        
            
        