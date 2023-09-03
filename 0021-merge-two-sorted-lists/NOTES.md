# Striver solution
* External space On1+n2 time On1+n2 nodes space:
```
h1 and h2, dummy node null, check which is smaller, point next of dummy to it once and for other than head point next of duplicatedummy to new node and move dupliactedummy, move heads
next of dummy node is head
```
* Inplace On1+n2 time O1 space :
```
just change next
l1 smaller list, l2 larger list, res is l1 first, temp=null initially
move l1 untill it is smaller than l2 and reassign temp to l1
temp's next points to l2
swap l1 l2
```
```
class Solution
{
public:
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
//Striver solution On1+n2 time O1 space
if (l1 == NULL)
return l2;
if (l2 == NULL)
return l1;
if (l1->val > l2->val)
swap(l1, l2);
ListNode *res = l1;
while (l1 != NULL && l2 != NULL)
{
ListNode *tmp = NULL;
while (l1 != NULL && l1->val <= l2->val)
{
tmp = l1;
l1 = l1->next;
}
tmp->next = l2;
swap(l1, l2);
}
return res;
}
};
```
# My solution
​
```
class Solution
{
public:
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
//My solution On time On space merge sort
ListNode *list1 = l1;
ListNode *list2 = l2;
vector<ListNode *> v;
​