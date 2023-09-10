while (itr ! = null ) {
if ( itr.random != null) {
itr.next.random = itr.random.next;
}
itr = itr.next.next;
}
itr = head
pseudohead = (0)
copy = pseudohead
while (itr!=null) {
front = itr.next.next
itr.next =front
copy =copy.next
itr =itr.next;
return pseudohead.next
​
```
/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;
Node(int _val) {
val = _val;
next = NULL;
random = NULL;
}
};
*/
​
class Solution {
public:
Node* copyRandomList(Node* head) {