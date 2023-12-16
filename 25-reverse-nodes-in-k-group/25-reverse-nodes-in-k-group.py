# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# class Solution:
#     def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

# couldn't solve

# neetcode solution
# O(n) time O(1) space
# reverse group of k nodes taking care of connecting previous with reversed list

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        dummy = ListNode(0, head)
        groupPrev = dummy

        while True:
            # kth node of current group
            kth = self.getKth(groupPrev, k)
            
            if not kth:
                break
                
            groupNext = kth.next
            
            
            # reverse group
            # 1st node of group gets connected to node next to K and similarly whole links in group gets reversed untill node next to group is reached
            # important concept to store node pointer in variable before breaking the link
            prev, curr = kth.next, groupPrev.next
            while curr != groupNext:
                tmp = curr.next
                curr.next = prev
                prev = curr
                curr = tmp
            
            tmp = groupPrev.next
            # group's previous points to new reversed list's first node i.e. original kth node
            groupPrev.next = kth
            # group's previous updates to point to last node of new reversed list i.e orginal groupPrev.next
            groupPrev = tmp
            
        return dummy.next

    def getKth(self, curr, k):
        while curr and k > 0:
            curr = curr.next
            k -= 1
        return curr

# Striver solution
# * O(n/k)*k time O1 space
# ```
# class Solution
# {
# public:
#     // Striver solution On time O1 space
#     ListNode *reverseKGroup(ListNode *head, int k)
#     {
#         if (head == NULL || k == 1)
#             return head;

#         ListNode *dummy = new ListNode(0);
#         dummy->next = head;

#         ListNode *cur = dummy, *nex = dummy, *pre = dummy;
#         int count = 0;

#         while (cur->next != NULL)
#         {
#             cur = cur->next;
#             count++;
#         }

#         while (count >= k)
#         {
#             // dummy is constant
#             // prev is moved before starting of the 1st position of group of size k
#             // cur is standing at first position and nex is standing at 2nd position of group of size k
#             cur = pre->next;
#             nex = cur->next;
#             for (int i = 1; i < k; i++) // watch video for reversing links one by one
#             {
#                 cur->next = nex->next;
#                 nex->next = pre->next;
#                 pre->next = nex;
#                 nex = cur->next;
#             }
#             pre = cur;
#             count -= k;
#         }
#         return dummy->next;
#     }
# };
# ```
# # My solution

# ```
# /**
#  * Definition for singly-linked list.
#  * struct ListNode {
#  *     int val;
#  *     ListNode *next;
#  *     ListNode() : val(0), next(nullptr) {}
#  *     ListNode(int x) : val(x), next(nullptr) {}
#  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
#  * };
#  */
# class Solution
# {
# public:
#     // My solution On time On space
#     ListNode *recur(ListNode *start, int counter, int k)
#     {
#         if (counter == 0)
#         {
#             return start;
#         }

#         ListNode *curr = start;
#         for (int i = 1; i <= k; i++)
#         {
#             start = start->next;
#         }
#         ListNode *prev = recur(start, counter - 1, k);
#         for (int j = 1; j <= k; j++)
#         {
#             ListNode *temp = curr->next;
#             curr->next = prev;
#             prev = curr;
#             curr = temp;
#         }
#         return prev;
#     }
#     ListNode *reverseKGroup(ListNode *head, int k)
#     {
#         ListNode *t = head;
#         int len = 0;
#         while (t != NULL)
#         {
#             len++;
#             t = t->next;
#         }

#         ListNode *start = head;

#         return recur(start, len / k, k);
#     }
# };
# ```   
            
            
            
                    