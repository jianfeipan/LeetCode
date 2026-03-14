/*
You are given the head of a singly linked list head and a positive integer k.

You must reverse the first k nodes in the linked list, and then reverse the next k nodes, and so on. If there are fewer than k nodes left, leave the nodes as they are.

Return the modified list after reversing the nodes in each group of k.

You are only allowed to modify the nodes' next pointers, not the values of the nodes.

Example 1:



Input: head = [1,2,3,4,5,6], k = 3

Output: [3,2,1,6,5,4]
Example 2:



Input: head = [1,2,3,4,5], k = 3

Output: [3,2,1,4,5]
Constraints:

The length of the linked list is n.
1 <= k <= n <= 100
0 <= Node.val <= 100

*/


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

class Solution {
public:
    // BF: a vector allows random access with index
    // time O(N) space: O(N)
    ListNode* reverseKGroup_vector_BF(ListNode* head, int k) {
        vector<ListNode*> nodes;
        auto current = head;
        while(current)
        {
            nodes.push_back(current);
            current = current->next;
        }

        int groupCount = nodes.size()/k;
        ListNode beforeFirst;
        auto prev = &beforeFirst;
        //reverse
        // 0 1 2 3 4 5: index
        // 1 2 3 4 5 6 k=3 group=2
        // gourp 0: nodes[1]->next = nodes[0]
        //          nodes[2]->next = nodes[1]
        //          prev = nodes[0]
        // 
        for(int group = 0; group<groupCount; ++group)
        {
            for(int i=1; i<k; ++i)
            {
                int index = group*k + i;
                nodes[index]->next = nodes[index-1];
            }
            prev->next = nodes[group*k+k-1];
            prev = nodes[group*k];
        }
        
        if(nodes.size() > groupCount*k)
            prev->next = nodes[groupCount*k];
        else
            prev->next = nullptr;

        return beforeFirst.next;
    }

    // solution 2 _vector_smaller
    // BF: a vector allows random access with index
    // optimization: smaller vector: only K element
    // time O(N) space: O(k)
    ListNode* reverseKGroup_smaller_vector(ListNode* head, int k) 
    {
        vector<ListNode*> group;
        group.reserve(k);
        ListNode beforeFirst;
        auto prev = &beforeFirst;

        auto current = head;
        while(current)
        {
            auto next = current->next;
            group.push_back(current);
            if(group.size()==k)
            {
                for(int i=1; i<group.size(); ++i)
                {
                    group[i]->next = group[i-1];
                }
                prev->next = group.back();
                prev = group.front();
                group.clear();
            }
            current = next;
        }

        prev->next = group.empty() ? nullptr : group.front();

        return beforeFirst.next;
    }

    // solution 3 
    // optimization:  any extra data structure is for knwoing the position, where to revers, where is the next begin
    // we can just use pointers
    // time O(N) space: O(1)
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode beforeFirst;
        auto prev = &beforeFirst;
        auto current = head;
        int counter = 0;

        auto reverse = [](ListNode * start, ListNode* end){
            if(start == end) return;
            auto prev = start;
            auto current = start->next;
            while(current!=end)
            {
                auto next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            end->next = prev;
            start->next = nullptr;//For saftly
        };

        ListNode* groupStart = current;
        ListNode* groupEnd = nullptr;
        while(current)
        {
            auto next = current->next;
            ++counter;
            if(counter == k){
                groupEnd = current;
                //reverse this group
                reverse(groupStart, groupEnd); //TODO
                prev->next = groupEnd;
                prev = groupStart;
                counter = 0;
                groupStart = next;
                groupEnd = nullptr;
            }
            current = next;
        }
        //assert(groupEnd == nullptr);
        prev->next = groupStart;
        return beforeFirst.next;
    }

    
};
