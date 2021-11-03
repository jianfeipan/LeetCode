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
#include <queue>

class Solution_double_queue {
private:
    std::queue<TreeNode*> levelA;
    std::queue<TreeNode*> levelB;
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        
        vector<vector<int>> levels;
        if(root)
        {

            levelA.push(root);
            while(!levelA.empty() || !levelB.empty())  
            {
                vector<int> level;


                if(!levelA.empty())
                {
                    level.reserve(levelA.size());
                    while(!levelA.empty())
                    {
                        TreeNode * current = levelA.front();
                        levelA.pop();
                        level.push_back(current->val);
                        if(current->left)
                        {
                            levelB.push(current->left);
                        }
                        if(current->right)
                        {
                            levelB.push(current->right);
                        }
                    }
                }
                else
                {
                    level.reserve(levelB.size());
                    while(!levelB.empty())
                    {
                        TreeNode * current = levelB.front();
                        levelB.pop();
                        level.push_back(current->val);
                        if(current->left)
                        {
                            levelA.push(current->left);
                        }
                        if(current->right)
                        {
                            levelA.push(current->right);
                        }
                    }
                }

                levels.push_back(level);

            }
        }
        return levels;
        
    }
};

class Solution_single_queue {
private:
    std::queue<TreeNode*> queue;
        
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        
        vector<vector<int>> levels;
        if(root)
        {
            queue.push(root);
            while(!queue.empty())  
            {
                vector<int> level;
                
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
