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

fact:
    1 deep clone
    2 cycle
idea
    1 recursive call to clone nodes
    2 need to avoid circle
        --> Node * input is node really easy to ideantify the cycle, 
        --> still need to have a visited map to traverse thegraph, with DFS or BFS
        --> when doing the copy, nothing can indice which one is copied from which one, only a index and an adj table will record the replations 
other solutions:
    here i used vector + map to map Node*-> int -> Node*
    however, we can onlyuse on map to do that ,map<Node*,Node*> old_to_new_mapping


*/

class Solution {

private:
    void dfs(Node* node, unordered_map<Node*, int> & node_index, vector<Node*> & index_node)
    {
        if(!node) return;
              
        auto it = node_index.find(node);
 
        if(it==node_index.end())
        {
            index_node.push_back(node);
            node_index[node] = index_node.size() -1;

            for(Node* neighbor : node->neighbors) dfs(neighbor, node_index, index_node);
        }
    }

public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        unordered_map<Node*, int> node_index;
        vector<Node*> index_node;
        dfs(node, node_index, index_node);

        vector<Node*> clonedNodes(index_node.size(), nullptr);
        for(int i = 0; i<clonedNodes.size(); ++i)//Clone value
        {
            clonedNodes[i] = new Node(index_node[i]->val);
        }

        for(int i = 0; i<clonedNodes.size(); ++i)//Branch neighbors
        {
            for(Node* neighbor : index_node[i]->neighbors)
            {
                int neighborIndex = node_index[neighbor];
                clonedNodes[i]->neighbors.push_back(clonedNodes[neighborIndex]);
            }
        }

        return clonedNodes[0];
    }
};
