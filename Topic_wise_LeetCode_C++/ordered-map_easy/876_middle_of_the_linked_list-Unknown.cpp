/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    ListNode *middleNode(ListNode *head)
    {
        // On time O1 space
        int len = 0;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            len++;
            curr = curr->next;
        }
        curr = head;

        for (int i = 0; i < len / 2; i++)
        {
            curr = curr->next;
        }

        return curr;
    }
};
// @lc code=end
