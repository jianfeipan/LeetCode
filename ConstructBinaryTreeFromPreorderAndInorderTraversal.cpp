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
class ConstructBinaryTreeFromPreorderAndInorderTraversal {
private : 
    TreeNode* buildTree(const std::vector<int>::iterator & preorderBegin,
                        const std::vector<int>::iterator & preorderEnd,
                        const std::vector<int>::iterator & inorderBegin,
                        const std::vector<int>::iterator & inorderEnd) 
    {
        TreeNode * root = new TreeNode(*preorderBegin);
        if(preorderEnd - preorderBegin > 0)
        {
            //find left and right sub tree then call recucivly the buildTree
            
            auto rootPosInorder = std::find(inorderBegin, inorderEnd+1, root->val);//this can be optimized by a mpa, which key is the element and the value is the position of the int value
            
            int leftSubTreeSize = rootPosInorder - inorderBegin;
            int rightSubTreeSize = inorderEnd - rootPosInorder;
            
            if(leftSubTreeSize > 0)
            {
                root->left = buildTree( preorderBegin+1, 
                                                  preorderBegin+leftSubTreeSize, 
                                                  inorderBegin, 
                                                  rootPosInorder-1);
            }

            if(rightSubTreeSize >0)
            {
                root->right =  buildTree(preorderBegin+leftSubTreeSize+1, 
                                                preorderEnd, 
                                                rootPosInorder+1,
                                                inorderEnd);
            }
            
            
        }

        return root;
    }    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
                
        return buildTree(preorder.begin(), preorder.end()-1, inorder.begin(), inorder.end()-1);
       
    }
        
};
