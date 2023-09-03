# Striver solution
Same as my solution
# Leetcode solution
Iterative same as my solution
Recursive :
```
public ListNode reverseList(ListNode head) {
if (head == null || head.next == null) return head;
ListNode p = reverseList(head.next);
head.next.next = head;
head.next = null;
return p;
}
```
# My solution
​
```
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution
{
public:
// My solution recursive On time On recursion stack space
ListNode *recur(ListNode *curr, ListNode *prev)
{
if (curr == nullptr)
return prev;
ListNode *temp = curr->next;
curr->next = prev;
prev = curr;