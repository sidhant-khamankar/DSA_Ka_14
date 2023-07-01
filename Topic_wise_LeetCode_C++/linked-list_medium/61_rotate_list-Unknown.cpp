/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    // Striver solution On time O1 space same as my solution just precise
    ListNode *rotateRight(ListNode *head, int k)
    {
        // edge cases
        if (!head || !head->next || k == 0)
            return head;

        // compute the length
        ListNode *cur = head;
        int len = 1;
        while (cur->next && ++len)
            cur = cur->next;

        // go till that node
        cur->next = head;
        k = k % len;
        k = len - k;
        while (k--)
            cur = cur->next;

        // make the node head and break connection
        head = cur->next;
        cur->next = NULL;

        return head;
    }

    //My solution On time O1 space
    // ListNode *rotateRight(ListNode *head, int k)
    // {
    //     if (head == NULL || k == 0)
    //     {
    //         return head;
    //     }
    //     int len = 0;
    //     ListNode *t = head;
    //     while (t != NULL)
    //     {
    //         len++;
    //         t = t->next;
    //     }
    //     if (len == 1)
    //     {
    //         return head;
    //     }
    //     int rev = len - (k % len);

    //     if (rev == len)
    //     {
    //         return head;
    //     }
    //     t = head;
    //     ListNode *prev;
    //     for (int i = 1; i <= rev; i++)
    //     {
    //         prev = t;
    //         t = t->next;
    //     }
    //     prev->next = NULL;
    //     ListNode *h = t;
    //     while (t->next != NULL)
    //     {
    //         t = t->next;
    //     }
    //     t->next = head;

    //     return h;
    // }
};
// @lc code=end
