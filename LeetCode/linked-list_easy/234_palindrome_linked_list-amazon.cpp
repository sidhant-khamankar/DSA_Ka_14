/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    //Striver solution On/2+n/2+n/2 time O1 space
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = NULL;
        ListNode *next = NULL;
        while (head != NULL)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseList(slow->next);
        slow = slow->next;

        while (slow != NULL)
        {
            if (head->val != slow->val)
            {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }

    // My solution On time O1 space
    // bool isPalindrome(ListNode *head)
    // {
    //     if (head == NULL)
    //     {
    //         return false;
    //     }
    //     else if (head->next == NULL)
    //     {
    //         return true;
    //     }
    //     ListNode *t = head;
    //     int len = 0;
    //     while (t != NULL)
    //     {
    //         len++;
    //         t = t->next;
    //     }

    //     int counter = (len % 2 == 0) ? len / 2 : (len / 2) + 1;

    //     ListNode *curr = head;
    //     ListNode *prev = NULL;
    //     for (int i = 1; i <= counter; i++)
    //     {
    //         prev = curr;
    //         curr = curr->next;
    //     }
    //     prev->next = NULL;

    //     ListNode *pre = NULL;
    //     while (curr != NULL)
    //     {
    //         ListNode *temp = curr->next;
    //         curr->next = pre;
    //         pre = curr;
    //         curr = temp;
    //     }

    //     t = head;
    //     while (pre != NULL && t != NULL)
    //     {
    //         if (pre->val != t->val)
    //         {
    //             return false;
    //         }
    //         pre = pre->next;
    //         t = t->next;
    //     }
    //     return true;
    // }
};
// @lc code=end
