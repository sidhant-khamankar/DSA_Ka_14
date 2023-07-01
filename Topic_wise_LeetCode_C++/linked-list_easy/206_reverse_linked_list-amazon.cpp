/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    // My solution recursive On time On recursion stack space
    ListNode *recur(ListNode *curr, ListNode *prev)
    {
        if (curr == nullptr)
            return prev;
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        return recur(curr, prev);
    }
    ListNode *reverseList(ListNode *head)
    {
        // My solution iterative On time O1 space
        // ListNode *curr = head;
        // ListNode *prev = nullptr;
        // while (curr != nullptr)
        // {
        //     ListNode *temp = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = temp;
        // }
        // return prev;

        ListNode *curr = head;
        ListNode *prev = nullptr;
        return recur(curr, prev);
    }
};
// @lc code=end
