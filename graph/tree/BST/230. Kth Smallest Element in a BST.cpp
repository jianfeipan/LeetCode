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
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        return inorderVisit(root, k)->val;    
    }
    
private:
    TreeNode * inorderVisit(TreeNode * root, int &k)
    {
        TreeNode * kth = nullptr;
        if(root)
        {
            kth = inorderVisit(root->left, k);

            if(k>0)
            {
                --k;
                if(k==0) kth = root;
                else kth = inorderVisit(root->right, k);
            }
        }
        return kth;
    }
};
