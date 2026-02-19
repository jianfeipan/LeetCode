/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
/*
we can try dfs: 
copy(root) : copy_root->child = copy(child)
how to avoid circles-> current doesn't get copy second time
*/
class Solution {
unordered_map<Node*, Node*> copied;
public:
    Node* cloneGraph(Node* node) {
        Node* res=nullptr;
        if(node){
            if(copied.contains(node)) return copied[node];

            copied[node] = new Node(node->val);
            for(Node* child : node->neighbors){
                copied[node]->neighbors.push_back(cloneGraph(child));
            }
        }
        return copied[node];
    }
};
