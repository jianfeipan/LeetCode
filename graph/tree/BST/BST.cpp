/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BST {
    
private:
    TreeNode* mostLeft(TreeNode* root)
    {
        if(!root->left)
            return root;
        else
            return mostLeft(root->left);  
    }
    
    TreeNode* mostRight(TreeNode* root)
    {
        if(!root->right)
            return root;
        else
            return mostRight(root->right);  
    }
    bool isValidBSTHelper(TreeNode* root, TreeNode* lefthigh, TreeNode* rightlow)
    {
        if(root == nullptr){
            return true;
        }
        if(lefthigh != nullptr && root->val <= lefthigh->val){
            return false;
        }
        if(rightlow != nullptr && root->val >= rightlow->val){
            return false;
        }
        return isValidBSTHelper(root->right, root, rightlow) && isValidBSTHelper(root->left, lefthigh, root);
    }
    
public:
    //from current  to children to find limits 
    bool isValidBST_1(TreeNode* root) 
    {
        bool isValide = false;
        if(root)
        {
            isValide = true;
        
            if(root->left)
            {
                TreeNode* mostRightNode = mostRight(root->left);
                isValide = isValide && ((mostRightNode->val)<root->val) && isValidBST(root->left);
                
            }

            if(root->right)
            {
                TreeNode* mostLeftNode = mostLeft(root->right);
                isValide = isValide && ((mostLeftNode->val)>root->val) && isValidBST(root->right);
            }
        }
        return isValide;
    }
    
    //faster solution: from current to parent to find limits
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, nullptr, nullptr); 
    }

 

};
