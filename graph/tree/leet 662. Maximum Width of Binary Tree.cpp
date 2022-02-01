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
    
private:
    int countWidth(std::list<TreeNode*> & levelQueue)
    {

        std::list<TreeNode*>::const_iterator it = levelQueue.begin();
        
        std::list<TreeNode*>::const_iterator from = levelQueue.end();
        for( ; it!=levelQueue.end(); ++it)
        {
            if(*it)
            {
                from = it;//first no null
                break;
            }
        }
        
        if(from == levelQueue.end())
            return 0;
        
        std::list<TreeNode*>::const_iterator to = it;
        for( ; it!=levelQueue.end(); ++it)
        {
            if(*it)
            {
                to = it; //last no null
            }
        }
        
        
        return std::distance(from, to) +1;
        
    }
public:
    //traversal by level 
    //level out put should be a full binary tree [a null, null , null , null b], and no null part will be the width
    //Time limit Exceeded
    
    int widthOfBinaryTree_BFS(TreeNode* root) {
        if(!root)
            return 0;
        
        int maxWidth = 1;
        std::list<TreeNode*> queue;
        queue.push_back(root);
        int currentLevelWidth = 1;
        
        while(!queue.empty() && currentLevelWidth >0)  
        {
            const int levelSize =queue.size();
            currentLevelWidth = countWidth(queue);
            
            if(currentLevelWidth >0)
            {
                if(maxWidth<currentLevelWidth)
                    maxWidth = currentLevelWidth;
                
                bool startCountNull = false;
                for(int i = 0; i < levelSize; ++i)
                {
                    TreeNode * node = queue.front();
                    if(node)
                    {
                        startCountNull = true;
                        queue.push_back(node->left);
                        queue.push_back(node->right);
                    }
                    else
                    {
                        if(startCountNull)
                        {
                            queue.push_back(nullptr);
                            queue.push_back(nullptr); 
                        }
                    }
                    queue.pop_front();
                }
            }

        }
        return maxWidth;
        
    }
    
    //O(N) traversal only once, use binary tree 's caractor : level nodes number is the depth ^ 2
    //
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<size_t> lefts; // left most nodes at each level;
        return dfs(root, 1, 0, lefts);
    }
private:
    size_t dfs(TreeNode* n, size_t id, size_t d, vector<size_t>& lefts) { // d : depth
        if (!n) return 0;
        if (d >= lefts.size()) //this condition makes only take the most left node then wait for next level to be true
            lefts.push_back(id);  // add left most node
        return max({id + 1 - lefts[d], dfs(n->left, id * 2, d + 1, lefts), dfs(n->right, id * 2 + 1, d + 1, lefts)});
    }
    
};
