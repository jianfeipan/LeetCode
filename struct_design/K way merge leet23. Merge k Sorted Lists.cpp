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
    //N way merge using minHeap
    ListNode* mergeKLists(vector<ListNode*>& lists) //O(N * logK) K lists, N nodes
    {
        ListNode merged;
        
        ListNode * currentMerged = &merged;
        
        auto greater = [](ListNode* left, ListNode* right){
            return left->val > right->val;
        };
        
        priority_queue<ListNode*,
            vector<ListNode*>,
            decltype(greater)
        > minHeap(greater);
        
        for(auto * head : lists) 
            if(head) minHeap.push(head);
        
        while(!minHeap.empty())
        {
            
            auto * minNode = minHeap.top();minHeap.pop();
            if(auto * next = minNode->next)
                minHeap.push(next);
            
            currentMerged->next = new ListNode(minNode->val);
            currentMerged = currentMerged->next;
        }
        
        return merged.next;
    }
    
    
    //N way merge
    ListNode* mergeKLists_with_compare_loop(vector<ListNode*>& lists)  //O(N * K) K lists, N nodes
    {
        ListNode merged;
        
        vector<ListNode*> current(lists);
        ListNode * currentMerged = &merged;
        
        bool stop = false;
        while(!stop)
        {
            int minIndex = -1;
            int min = INT_MAX;
            for(size_t i = 0; i<lists.size(); ++i)
            {
                if(current[i] && min>current[i]->val)
                {
                    min = current[i]->val;
                    minIndex = i;
                }
            }
            if(minIndex>=0)
            {
                current[minIndex] = current[minIndex]->next;
                currentMerged->next = new ListNode(min);
                currentMerged = currentMerged->next;
            }
            else
                stop = true;
        }
        
        return merged.next;
    }
};
