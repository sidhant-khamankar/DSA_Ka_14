/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    // My solution Omn time On+m space
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA != NULL)
        {
            for (ListNode *l1 = headA; l1 != NULL; l1 = l1->next)
            {
                for (ListNode *l2 = headB; l2 != NULL; l2 = l2->next)
                {
                    if (l1 == l2)
                    {
                        return l1;
                    }
                }
            }
        }
        else
        {
            for (ListNode *l2 = headB; l2 != NULL; l2 = l2->next)
            {
                for (ListNode *l1 = headA; l1 != NULL; l2 = l1->next)
                {
                    if (l1 == l2)
                    {
                        return l1;
                    }
                }
            }
        }

        return NULL;
    }
};
// @lc code=end
