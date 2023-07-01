/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        


        // My solution On time On space
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->next == nullptr)
        {
            return nullptr;
        }

        if (n == 0)
        {
            return head;
        }
        vector<ListNode *> v;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            v.push_back(curr);
            curr = curr->next;
        }
        if (v.size() - n - 1 == -1)
        {
            v.erase(v.begin());
        }
        else
        {
            v[v.size() - n - 1]->next = v[v.size() - n - 1]->next->next;
        }

        return v[0];
    }
};
// @lc code=end
