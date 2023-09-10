# Striver solution
* get length, subtract n from it On+On time O1 space
```
then move from head till updated length and update its next
delete(node) //optional
edge case delete first node
node =head
h = h->n
delete(node)
```
* dummy node's next points to head On time O1 space
```
fast = slow = dummy
fast moves n, then fast and slow move by 1 step
slow->next = slow->next->next;
edge case delete head
fast reached last node
slow->next = slow->next->next;
return dummy->next;
code same as leetcode solution
```
# Leetcode solution
* Two Pointers with n gap between them
```
public ListNode removeNthFromEnd(ListNode head, int n) {
ListNode dummy = new ListNode(0);
dummy.next = head;
ListNode first = dummy;
ListNode second = dummy;
// Advances first pointer so that the gap between first and second is n nodes apart
for (int i = 1; i <= n + 1; i++) {
first = first.next;
}
// Move first to the end, maintaining the gap
while (first != null) {
first = first.next;
second = second.next;
}
second.next = second.next.next;
return dummy.next;
}
```
# My solution
​
```
class Solution
{
public:
ListNode *removeNthFromEnd(ListNode *head, int n)
{
// My solution On time On space
if (head == nullptr)
{