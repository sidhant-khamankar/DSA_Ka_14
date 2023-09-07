# KnowledgeCenter solution
​
```
// KnowledgeCenter solution On time O1 space
void reorderList(ListNode *head)
{
if (!head || !head->next)
return;
​
// Get middle using slow and fast pointer
ListNode *slow = head, *fast = head;
while (fast && fast->next)
{
slow = slow->next;
fast = fast->next->next;
}
ListNode *prev = nullptr, *curr = slow, *tmp;
​
// reverse second part
while (curr)
{
tmp = curr->next;
curr->next = prev;
prev = curr;
curr = tmp;
}
​
// merge
ListNode *n1 = head, *n2 = prev;
while (n2->next)
{
tmp = n1->next;
n1->next = n2;
n1 = tmp;
​
tmp = n2->next;
n2->next = n1;
n2 = tmp;
}
}
```
​
# My solution
​
```
// My solution On time On space
// void reorderList(ListNode *head)
// {
​