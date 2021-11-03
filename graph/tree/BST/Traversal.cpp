/**
 * Definition for a binary tree node.
 */

 #include <queue>
 #include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 


class BSTTranserval {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) 
    {
        std::vector<std::vector<int>> levels;
        if(root)
        {
            std::queue<TreeNode*> queue;
            queue.push(root);
            while(!queue.empty())  
            {
                std::vector<int> level;
                
                const int levelSize =queue.size();
                level.reserve(levelSize);
                
                for(int i = 0; i < levelSize; ++i)
                {
                    TreeNode * current = queue.front();
                    queue.pop();
                    level.push_back(current->val);
                    if(current->left)
                    {
                        queue.push(current->left);
                    }
                    if(current->right)
                    {
                        queue.push(current->right);
                    }
                }
                levels.push_back(level);
            }
        }
        return levels;
    }
};
