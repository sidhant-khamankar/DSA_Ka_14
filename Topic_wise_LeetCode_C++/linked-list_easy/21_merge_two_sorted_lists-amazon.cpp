/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        //Striver solution On1+n2 time O1 space
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val > l2->val)
            swap(l1, l2);
        ListNode *res = l1;
        while (l1 != NULL && l2 != NULL)
        {
            ListNode *tmp = NULL;
            while (l1 != NULL && l1->val <= l2->val) //l1 - 1,2,4  l2 - 1,3,4
            {
                tmp = l1;
                l1 = l1->next;
            }               // l1 - 2,4 | 3,4 | 4 | NULL
            tmp->next = l2; // res - 1,1,3,4 | 1,1,2,4 | 1,1,2,3,4 | 1,1,2,3,4,4  l2 - 1,3,4 | 2,4 | 3,4 | 4
            swap(l1, l2);
        }
        return res;

        //My solution On time On space merge sort
        // ListNode *list1 = l1;
        // ListNode *list2 = l2;
        // vector<ListNode *> v;

        // while (list1 != nullptr && list2 != nullptr)
        // {
        //     if (list1->val <= list2->val)
        //     {
        //         ListNode *temp = list1;
        //         v.push_back(temp);
        //         list1 = list1->next;
        //     }
        //     else
        //     {
        //         ListNode *temp = list2;
        //         v.push_back(temp);
        //         list2 = list2->next;
        //     }
        // }

        // while (list1 != nullptr)
        // {
        //     ListNode *temp = list1;
        //     v.push_back(temp);
        //     list1 = list1->next;
        // }

        // while (list2 != nullptr)
        // {
        //     ListNode *temp = list2;
        //     v.push_back(temp);
        //     list2 = list2->next;
        // }

        // ListNode *head = nullptr;
        // if (v.size() <= 1)
        // {
        //     if (l1 != nullptr)
        //         return head = l1;
        //     else if (l2 != nullptr)
        //         return head = l2;
        //     else
        //         return head;
        // }
        // head = v[0];
        // ListNode *curr = v[1];
        // head->next = curr;

        // for (int i = 2; i < v.size(); i++)
        // {
        //     ListNode *temp = v[i];
        //     temp->next = nullptr;
        //     curr->next = temp;
        //     curr = curr->next;
        // }
        // return head;
    }
};
// @lc code=end
