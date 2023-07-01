/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    // KnowledgeCenter solution On time O1 space
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;

        // Get middle using slow and fast pointer
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = nullptr, *curr = slow, *tmp;

        // reverse second part
        while (curr)
        {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        // merge
        ListNode *n1 = head, *n2 = prev;
        while (n2->next)
        {
            tmp = n1->next;
            n1->next = n2;
            n1 = tmp;

            tmp = n2->next;
            n2->next = n1;
            n2 = tmp;
        }
    }
    // My solution On time On space
    // void reorderList(ListNode *head)
    // {

    //     vector<ListNode *> ll;

    //     while (head != NULL)
    //     {
    //         ll.push_back(head);
    //         head = head->next;
    //     }

    //     ListNode *curr = new ListNode();
    //     ListNode *dummy = new ListNode();
    //     dummy->next = curr;

    //     int l = 0, r = ll.size() - 1;
    //     int i = 0;
    //     while (l <= r)
    //     {
    //         if (i % 2 == 0)
    //             curr->next = ll[l++];
    //         else
    //             curr->next = ll[r--];
    //         curr = curr->next;
    //         i++;
    //     }
    //     curr->next = NULL;
    //     // ListNode *temp = dummy->next->next;
    //     // while(temp!=NULL) {
    //     //     cout<<temp->val<<" ";
    //     //     temp= temp->next;
    //     // }
    //     head = dummy->next->next;
    // }
};
// @lc code=end
