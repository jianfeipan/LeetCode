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

/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.


facts:
    1. single lined-list
    2 have the head as input
    3 need to access the last nodes frequently 

idea:
    1 I will need a vector to access last pointers.
    2 two things i need to do:
        - 1->next to n
        - n->next to 2
pay atention:
    vector index  boundry !!




*/
 
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;

        while(head)
        {
            nodes.push_back(head);

            head = head->next;
        }

        for(int i =0; i<nodes.size()/2; ++i)
        {
            nodes[nodes.size()-i -1]->next = nodes[i]->next;
            nodes[i]->next = nodes[nodes.size()-i -1];
        }
        nodes[nodes.size()/2]->next = nullptr;

        head = nodes[0];
    }
};
