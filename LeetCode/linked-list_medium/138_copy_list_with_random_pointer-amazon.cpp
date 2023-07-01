/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    //Striver solution On time O1 space
    Node *copyRandomList(Node *head)
    {
        Node *iter = head;
        Node *front = head;

        // First round: make copy of each node,
        // and link them together side-by-side in a single list.
        while (iter != NULL)
        {
            front = iter->next;

            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;

            iter = front;
        }

        // Second round: assign random pointers for the copy nodes.
        iter = head;
        while (iter != NULL)
        {
            if (iter->random != NULL)
            {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }

        // Third round: restore the original list, and extract the copy list.
        iter = head;
        Node *pseudoHead = new Node(0);
        Node *copy = pseudoHead;

        while (iter != NULL)
        {
            front = iter->next->next;

            // extract the copy
            copy->next = iter->next;

            // restore the original list
            iter->next = front;

            copy = copy->next;
            iter = front;
        }

        return pseudoHead->next;
    }
};

// class Solution
// {
// public:
//     //My solution On time On space
//     Node *copyRandomList(Node *head)
//     {
//         if (head == NULL)
//         {
//             return head;
//         }

//         unordered_map<Node *, Node *> mp;
//         Node *i = head;
//         Node *j = new Node(i->val);
//         mp.insert({i, j});

//         Node *dummy = new Node(0);
//         dummy->next = j;

//         while (i != NULL && j != NULL)
//         {
//             if (i->next != NULL)
//             {
//                 if (mp.find(i->next) != mp.end())
//                 {
//                     j->next = mp[i->next];
//                 }
//                 else
//                 {
//                     j->next = new Node(i->next->val);
//                     mp.insert({i->next, j->next});
//                 }
//             }
//             if (i->random != NULL)
//             {
//                 if (mp.find(i->random) != mp.end())
//                 {
//                     j->random = mp[i->random];
//                 }
//                 else
//                 {
//                     j->random = new Node(i->random->val);
//                     mp.insert({i->random, j->random});
//                 }
//             }

//             i = i->next;
//             j = j->next;
//         }

//         return dummy->next;
//     }
// };
// @lc code=end
