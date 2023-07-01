/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
    bool hasCycle(ListNode *head)
    {
        //My solution same as striver, leetcode solution tortoise approach On time O1 space
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
                return false;
            }
        } while (slow != fast);

        return true;
    }
};
// @lc code=end
