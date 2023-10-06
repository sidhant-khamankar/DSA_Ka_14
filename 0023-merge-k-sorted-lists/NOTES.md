# Tech dose solutions
​
```
// Techdose solution
// 1. Array of pointers and point to starting of all linked lists
// compare all pointers and take minimum and increment that pointer
// Onk time On space if did inplace O1 space
​
// 2. join all linked lists and then use merge sort
// Onlogn time On space if did inplace O1 space
​
// 3. divide and conquer:like merge sort
// number of nodes * number of levels time
// Onlogk time On space if did inplace O1 space
​
// 4. Heap push pop logk time
// Ok+nlogk build heap + push/pop for n nodes time On space if did inplace O1 space
​
// 4. Heap
// class Solution
// {
//     struct node
//     {
//         ListNode *curr; //Current node
//         int idx;        //List index number
//         node(ListNode *a, int b)