/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    /*
    idea: BFS : same level don't agree uncomplete node on right side
    */
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root)
            return false;
        std::queue<TreeNode*> queue;
        queue.push(root);
        
        bool nullFound = false;
        while(!queue.empty())
        {
            const size_t currentLevelSize = queue.size();
            
            for(size_t i = 0; i < currentLevelSize; ++i)
            {
                auto node = queue.front();
                queue.pop();
                if(nullFound)
                {
                    if(node)
                        return false;
                }
                else
                {
                    if(node)
                    {
                        queue.push(node->left);
                        queue.push(node->right);
                    }
                    else
                    {
                        nullFound = true;
                    }
                }
            }     

        }
        
        return true;
    }
};
