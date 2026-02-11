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
    // loop {take the smallest head of lists}
    // L lists N numbers: O(N*L)
    // space: O(L)
    ListNode* mergeKLists_one_pass_find_min(vector<ListNode*>& lists) 
    {
        ListNode beforeFirst;
        auto prev = &beforeFirst;
        vector<ListNode*> currents(lists);
        while(true){
            int minIndex = -1;
            int minVal = INT_MAX;
            for(int i = 0; i<currents.size(); ++i)
            {
                auto current = currents[i];
                if(current)
                {
                    if(minVal > current->val)
                    {
                        minVal = current->val;
                        minIndex = i;
                    }
                }
                
            }
            if(minIndex==-1) break;

            prev->next = currents[minIndex];
            prev = currents[minIndex];
            currents[minIndex] = currents[minIndex]->next;
        }

        return beforeFirst.next;
        
    }
    
    // solution2: use minstack to find min instead of one pass: L -> logL
    // minstack { take the smallest head of lists}
    // L lists N numbers: O(NlogL)
    // space: O(L)
    ListNode* mergeKLists_minstack(vector<ListNode*>& lists) 
    {
        auto greater = [](ListNode* l, ListNode*r)
                    {
                        return l->val > r->val;//greater->minheap
                    };
        priority_queue<ListNode*, vector<ListNode*>, decltype(greater)> minStack(greater);
        for(auto node : lists)
        {
            minStack.push(node);
        }
        ListNode beforeFirst;
        auto prev = &beforeFirst;
        while(!minStack.empty())
        {
            auto minNode = minStack.top();
            prev->next = minNode;
            minStack.pop();
            if(minNode->next)
                minStack.push(minNode->next);

            prev = prev->next;
        }
        return beforeFirst.next;
    }

    //solution 3 devide and conquer-> merg sort
    // let's merge half lists first, them merge to the final
    // recursivly we can merge first half of the half..
    ListNode* _mergeKLists_merge_sort(int from, int to, vector<ListNode*>& lists)
    {   // 0, 1, 2
        // f. m  t
        cout<< from<<"-"<<to<<endl;
        if(from>to) return nullptr;
        if(from == to) return lists[from];

        const int middle = from + (to-from) / 2;
        auto first = _mergeKLists_merge_sort(from, middle, lists);
        auto second = _mergeKLists_merge_sort(middle+1, to, lists);

        ListNode beforeFirst;
        auto prev = &beforeFirst;

        while(first && second)
        {
            if(first->val <= second->val)
            {
                prev->next = first;
                first = first->next;
            }
            else
            {
                prev->next = second;
                second = second->next;
            }
            prev = prev->next;
        }

        if(first) prev->next = first;
        if(second) prev->next = second;

        return beforeFirst.next;
    }
    //_merge_sort
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        return _mergeKLists_merge_sort(0, lists.size()-1, lists);
    }

};
