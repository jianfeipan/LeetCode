/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        /*
        idea BFS, level by level, link in side level in order
        */
        if(!root) return nullptr;//throw new invalid_parameter();
        
        queue<Node*> level;
        
        level.push(root);
        
        while(!level.empty())
        {
            int levelSize = level.size();
            
            Node* prev = level.front();level.pop();;
            if(prev->left) level.push(prev->left);
            if(prev->right) level.push(prev->right);

            while(--levelSize > 0)
            {
                auto current = level.front();level.pop();  
                
                if(current->left) level.push(current->left);
                if(current->right) level.push(current->right);
                
                prev->next = current;
                prev = current;
            }
            prev->next = nullptr;
        }
        
        return root;
        
    }
};
