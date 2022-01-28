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
    //N way merge
    ListNode* mergeKLists(vector<ListNode*>& lists) 
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
