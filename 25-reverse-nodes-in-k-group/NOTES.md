# Striver solution
* O(n/k)*k time O1 space
```
class Solution
{
public:
// Striver solution On time O1 space
ListNode *reverseKGroup(ListNode *head, int k)
{
if (head == NULL || k == 1)
return head;
​
ListNode *dummy = new ListNode(0);
dummy->next = head;
​
ListNode *cur = dummy, *nex = dummy, *pre = dummy;
int count = 0;
​
while (cur->next != NULL)
{
cur = cur->next;
count++;
}
​
while (count >= k)
{
// dummy is constant
// prev is moved before starting of the 1st position of group of size k
// cur is standing at first position and nex is standing at 2nd position of group of size k
cur = pre->next;
nex = cur->next;
for (int i = 1; i < k; i++) // watch video for reversing links one by one
{
cur->next = nex->next;
nex->next = pre->next;
pre->next = nex;
nex = cur->next;
}
pre = cur;
count -= k;
}
return dummy->next;
}
};
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