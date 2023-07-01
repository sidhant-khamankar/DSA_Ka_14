/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
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
    // My solution O1 time O1 space
    void deleteNode(ListNode *node)
    {
        if (node != NULL)
        {
            node->val = node->next->val;
            node->next = node->next->next;
        }
    }
};
// @lc code=end
