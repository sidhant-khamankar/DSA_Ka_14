/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    // Striver solution
    // max(n1, n2) time On space new linkedlist, code same as leetcode solution
    // Leetcode solution same as my solution just less code
    // Java code
    // ListNode addTwoNumbers(ListNode l1, ListNode l2)
    // {
    //     ListNode dummyHead = new ListNode(0);
    //     ListNode p = l1, q = l2, curr = dummyHead;
    //     int carry = 0;
    //     while (p != null || q != null)
    //     {
    //         int x = (p != null) ? p.val : 0;
    //         int y = (q != null) ? q.val : 0;
    //         int sum = carry + x + y; //not right to left addition is being performed
    //         carry = sum / 10;
    //         curr.next = new ListNode(sum % 10);
    //         curr = curr.next;
    //         if (p != null)
    //             p = p.next;
    //         if (q != null)
    //             q = q.next;
    //     }
    //     if (carry > 0)
    //     {
    //         curr.next = new ListNode(carry);
    //     }
    //     return dummyHead.next;
    // }
    // My solution On time On space
    // ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    // {
    //     ListNode *list1 = l1;
    //     ListNode *list2 = l2;
    //     int carry = 0;
    //     ListNode *res = new ListNode(-1);
    //     ListNode *head = new ListNode(-1);

    //     int f = list1->val + list2->val + carry;

    //     if (f > 9)
    //     {
    //         f = f - 10;
    //         carry = 1;
    //     }
    //     else
    //     {
    //         carry = 0;
    //     }
    //     res = new ListNode(f);
    //     head->next = res;
    //     list1 = list1->next;
    //     list2 = list2->next;

    //     while (list1 != NULL && list2 != NULL)
    //     {
    //         int val1 = list1->val;
    //         int val2 = list2->val;
    //         int fval = val1 + val2 + carry;

    //         if (fval > 9)
    //         {
    //             fval = fval - 10;
    //             carry = 1;
    //         }
    //         else
    //         {
    //             carry = 0;
    //         }
    //         res->next = new ListNode(fval);
    //         res = res->next;
    //         list1 = list1->next;
    //         list2 = list2->next;
    //     }

    //     while (list1 != NULL)
    //     {
    //         int val1 = list1->val;
    //         int fval = val1 + carry;

    //         if (fval > 9)
    //         {
    //             fval = fval - 10;
    //             carry = 1;
    //         }
    //         else
    //         {
    //             carry = 0;
    //         }
    //         res->next = new ListNode(fval);
    //         res = res->next;
    //         list1 = list1->next;
    //     }

    //     while (list2 != NULL)
    //     {
    //         int val2 = list2->val;
    //         int fval = val2 + carry;

    //         if (fval > 9)
    //         {
    //             fval = fval - 10;
    //             carry = 1;
    //         }
    //         else
    //         {
    //             carry = 0;
    //         }
    //         res->next = new ListNode(fval);
    //         res = res->next;
    //         list2 = list2->next;
    //     }

    //     if (carry)
    //     {
    //         res->next = new ListNode(carry);
    //     }

    //     return head->next;
    // }
};
// @lc code=end
