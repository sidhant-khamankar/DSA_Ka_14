/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        //My solution floyd cycle detection algorithm tortoise approach On+n time O1 space
        ListNode *slow = head;
        ListNode *fast = head;
        do
        {
            if (fast != NULL && fast->next != NULL && fast->next->next != NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            else
            {
                return NULL;
            }
        } while (slow != fast);

        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
// @lc code=end
