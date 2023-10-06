# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# My approach - have pointers to start of linked list and comapre all

# neetcode solution
# merge sort
# O(nlogk) as during merge sort all k linked lists gets divided by 2 after every step. So total of logk steps for all n values
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if not lists or len(lists) == 0:
            return None

        while len(lists) > 1:
            mergedLists = []
            for i in range(0, len(lists), 2):
                l1 = lists[i]
                l2 = lists[i + 1] if (i + 1) < len(lists) else None
                mergedLists.append(self.mergeList(l1, l2))
            lists = mergedLists
        return lists[0]

    def mergeList(self, l1, l2):
        dummy = ListNode()
        tail = dummy

        while l1 and l2:
            if l1.val < l2.val:
                tail.next = l1
                l1 = l1.next
            else:
                tail.next = l2
                l2 = l2.next
            tail = tail.next
        if l1:
            tail.next = l1
        if l2:
            tail.next = l2
        return dummy.next

# Tech dose solutions

# ```
# // Techdose solution
#     // 1. Array of pointers and point to starting of all linked lists
#     // compare all pointers and take minimum and increment that pointer
#     // Onk time On space if did inplace O1 space

#     // 2. join all linked lists and then use merge sort
#     // Onlogn time On space if did inplace O1 space

#     // 3. divide and conquer:like merge sort
#     // number of nodes * number of levels time
#     // Onlogk time On space if did inplace O1 space

#     // 4. Heap push pop logk time
#     // Ok+nlogk build heap + push/pop for n nodes time On space if did inplace O1 space

#     // 4. Heap
#     // class Solution
#     // {
#     //     struct node
#     //     {
#     //         ListNode *curr; //Current node
#     //         int idx;        //List index number
#     //         node(ListNode *a, int b)
#     //         {
#     //             curr = a;
#     //             idx = b;
#     //         }
#     //     };
#     //     struct compare
#     //     {
#     //         bool operator()(node a, node b)
#     //         {
#     //             return a.curr->val > b.curr->val;
#     //         }
#     //     };

#     // public:
#     //     ListNode *mergeKLists(vector<ListNode *> &lists)
#     //     {
#     //         int k = lists.size();
#     //         if (k == 0)
#     //             return NULL;
#     //         ListNode *head, *tail;
#     //         head = tail = NULL;
#     //         priority_queue<node, vector<node>, compare> heap;
#     //         vector<ListNode *> ptr(k); //Current node ptrs for all the lists
#     //         //Assign all the current ptrs and BUILD_HEAP
#     //         for (int i = 0; i < k; ++i)
#     //         {
#     //             ptr[i] = lists[i];
#     //             if (ptr[i] != NULL)
#     //                 heap.push(node(ptr[i], i));
#     //         }

#     //         if (heap.empty())
#     //             return NULL;
#     //         //Insert 1st node
#     //         head = tail = heap.top().curr;
#     //         int idx = heap.top().idx;
#     //         heap.pop();
#     //         ptr[idx] = ptr[idx]->next;
#     //         if (ptr[idx]) //Push newly pointed node if not NULL
#     //             heap.push(node(ptr[idx], idx));

#     //         //Make list with rest of the nodes
#     //         while (!heap.empty())
#     //         {
#     //             ListNode *temp = heap.top().curr; //Pop root node
#     //             idx = heap.top().idx;
#     //             heap.pop();

#     //             tail->next = temp; //Add newnode to list
#     //             tail = tail->next;
#     //             ptr[idx] = ptr[idx]->next; //Update current pointer
#     //             if (ptr[idx])              //Push newly pointed node if not NULL
#     //                 heap.push(node(ptr[idx], idx));
#     //         }
#     //         return head;
#     //     }
#     // };

#     // ##########################################################################
#     // ##########################################################################

#     // 3. Divide_&_Conquer
#     // class Solution
#     // {
#     //     ListNode *merge(vector<ListNode *> &lists, int left, int right)
#     //     {
#     //         if (left == right) //Only 1 list,therefore can't be merged
#     //             return lists[left];

#     //         int k = right - left + 1; //No of current lists
#     //         ListNode *head, *h1, *h2, *ptr;
#     //         head = h1 = h2 = NULL;
#     //         h1 = merge(lists, left, left + k / 2 - 1); //Merge 1st half and store its head in h1
#     //         h2 = merge(lists, left + k / 2, right);    //Merge 2nd half and store its head in h2

#     //         //Merge h1 and h2 into head
#     //         if (!h1 and !h2) //No list is present
#     //             return head;
#     //         else if (!h1) //Only 2nd list is present
#     //             return h2;
#     //         else if (!h2) //Only 1st list is present
#     //             return h1;

#     //         if (!h1 or (h1 and h1->val > h2->val))
#     //         {
#     //             head = h2;
#     //             h2 = h2->next;
#     //         }
#     //         else
#     //         {
#     //             head = h1;
#     //             h1 = h1->next;
#     //         }

#     //         ptr = head;
#     //         while (h1 or h2)
#     //         {
#     //             if (!h1)
#     //             {
#     //                 ptr->next = h2;
#     //                 h2 = h2->next;
#     //                 ptr = ptr->next;
#     //             }
#     //             else if (!h2)
#     //             {
#     //                 ptr->next = h1;
#     //                 h1 = h1->next;
#     //                 ptr = ptr->next;
#     //             }
#     //             else if (h1->val < h2->val)
#     //             {
#     //                 ptr->next = h1;
#     //                 h1 = h1->next;
#     //                 ptr = ptr->next;
#     //             }
#     //             else
#     //             {
#     //                 ptr->next = h2;
#     //                 h2 = h2->next;
#     //                 ptr = ptr->next;
#     //             }
#     //         }
#     //         return head;
#     //     }

#     // public:
#     //     ListNode *mergeKLists(vector<ListNode *> &lists)
#     //     {
#     //         int k = lists.size();
#     //         if (k == 0)
#     //             return NULL;
#     //         else if (k == 1)
#     //             return lists[0];
#     //         ListNode *head, *h1, *h2, *ptr;
#     //         head = h1 = h2 = NULL;
#     //         h1 = merge(lists, 0, k / 2); //Merge 1st half
#     //         if (k / 2 + 1 <= k - 1)
#     //             h2 = merge(lists, k / 2 + 1, k - 1); //Merge 2nd half

#     //         //Merge h1 and h2 into head
#     //         if (!h1 and !h2) //No list is present
#     //             return head;
#     //         else if (!h1) //Only 2nd list is present
#     //             return h2;
#     //         else if (!h2) //Only 1st list is present
#     //             return h1;

#     //         if (!h1 or (h1 and h1->val > h2->val))
#     //         {
#     //             head = h2;
#     //             h2 = h2->next;
#     //         }
#     //         else
#     //         {
#     //             head = h1;
#     //             h1 = h1->next;
#     //         }

#     //         ptr = head;
#     //         while (h1 or h2)
#     //         {
#     //             if (!h1)
#     //             {
#     //                 ptr->next = h2;
#     //                 h2 = h2->next;
#     //                 ptr = ptr->next;
#     //             }
#     //             else if (!h2)
#     //             {
#     //                 ptr->next = h1;
#     //                 h1 = h1->next;
#     //                 ptr = ptr->next;
#     //             }
#     //             else if (h1->val < h2->val)
#     //             {
#     //                 ptr->next = h1;
#     //                 h1 = h1->next;
#     //                 ptr = ptr->next;
#     //             }
#     //             else
#     //             {
#     //                 ptr->next = h2;
#     //                 h2 = h2->next;
#     //                 ptr = ptr->next;
#     //             }
#     //         }
#     //         return head;
#     //     }
#     // };

# ```
# # My solution

# ```
# // My solution Ok*max(length of linked lists) time Ok*max(length of linked lists) space
#     // ListNode *mergeKLists(vector<ListNode *> &lists)
#     // {
#     //     multiset<int> ms;
#     //     for (ListNode *t : lists)
#     //     {
#     //         while (t != NULL)
#     //         {
#     //             ms.insert(t->val);
#     //             t = t->next;
#     //         }
#     //     }

#     //     ListNode *dummy = new ListNode();
#     //     ListNode *dup_dummy = dummy;

#     //     for (auto &ele : ms)
#     //     {
#     //         dup_dummy->next = new ListNode(ele);
#     //         dup_dummy = dup_dummy->next;
#     //     }

#     //     return dummy->next;
#     // }
# ```

# Leetcode solutions

# ```

# ```
