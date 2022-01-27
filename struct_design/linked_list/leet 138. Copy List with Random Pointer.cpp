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

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        return copyRandomList_make_use_of_random_pointer(head);
    }
    Node* copyRandomList_make_use_of_random_pointer(Node* head) 
    {
        if(!head) return nullptr;
        
        auto current = head;
        while(current)//create new node store them on the next path (random path will not working, because random is not well to restore later)
        {
            auto newNode = new Node(current->val);
            
            newNode->next = current->next;//use the random as a temp register
            current->next = newNode;
            
            current = newNode->next;
        }
        
        auto copiedHead = head->next;
        
        current = head;
        while(current)//link the copies random pointers
        {
            current->next->random = current->random ? current->random->next : nullptr;
            
            current = current->next->next;
        }
        
        current = head;
        while(current)//fix the next of originals
        {
            auto currentCopied = current->next;
            current->next = currentCopied->next;
            currentCopied->next = current->next ? current->next->next : nullptr;

            current = current->next;
        }
        
        return copiedHead;
        
    }

    
    
    
    Node* copyRandomList_refind_random_with_order(Node* head) 
    {
        vector<int> randomPos = findRandomPos(head);//O(N)
        
        Node * copied = copyList(head);//O(N)
        
        fillRamdoms(copied, randomPos);//O(N^2)
        
        return copied;
    }

 private:
    void fillRamdoms(Node * head, const vector<int> & randomPos)
    {
        vector<Node*> nodesInOrder;nodesInOrder.reserve(randomPos.size());
        auto current = head;
        int count = 0;
        while(current)
        {
            nodesInOrder.push_back(current);
            ++count;
            current = current->next;
        }
        
        current = head;
        int index = 0;
        while(current)
        {
            const int randomIndex = randomPos[index];
            if(randomIndex >=0 ) current->random = nodesInOrder[randomIndex];
            
            current=current->next;
            ++index;
        }
    }
    
    Node * getNode(Node * head, int pos)
    {
        if(pos<0) return nullptr;
        
        while(pos--)
        {
            if(!head) throw invalid_argument("position out of boundry.");
            head=head->next;
        }
        
        return head;
    }
    
    vector<int> findRandomPos(Node* head)
    {
        vector<int> randomPos;
        
        unordered_map<Node*, int> order;
        order[nullptr] = -1;
        
        auto current = head;
        int count = 0;
        while(current)
        {
            order[current] = count;
            ++count;
            current = current->next;
        }
        
        randomPos.reserve(order.size());
        
        current = head;
        while(current)
        {
            randomPos.push_back(order[current->random]);
            current = current->next;
        }
        return randomPos;
    }
    
    Node* copyList(Node* head) 
    {
        if(head == nullptr) return nullptr;
        
        Node * copied = new Node(head->val);
        
        copied->next = copyRandomList(head->next);
        
        return copied;
    }
        
};
