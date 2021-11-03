 
/*
use # as null node
*/



TreeNode * constructTree(const vector<string> & nodes)
    {
        if(nodes.empty())
            return nullptr;
        
        TreeNode * root = new TreeNode(nodes[0]);
        
        std::stack<TreeNode *> stack;
        
        stack.push(root);
        int i = 1;
        for(; i<nodes.size() && !stack.empty() ;i++)
        {
            const string & val = nodes[i];
            
            TreeNode * last = stack.top();
            
            if(last->left == nullptr)
            {
                last->left = new TreeNode(val);
                if(val=="#")
                {
                    
                }
                else
                {
                    stack.push(last->left);
                }
            }
            else if(last->right == nullptr)
            {
                last->right = new TreeNode(val);
                stack.pop();
                if(val=="#")
                {
                }
                else
                {
                    stack.push(last->right);
                }
            }
            else
            {
                
            }
        }
        
        if(i<nodes.size()-1)//unvalide preorder list
            return nullptr;
        
        return root;
    }
