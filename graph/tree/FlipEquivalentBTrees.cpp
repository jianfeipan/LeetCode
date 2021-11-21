/*
For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.

[]
[]
[1]
[]
[1]
[1]
[1]
[2]
[1, 2]
[1]
[1,2]
[1,2]
[1,2,null,3]
[1,2,null,4]
[1,2]
[1,null,2]
[1,2,3,4,5,6,null,null,null,7,8]
[1,3,2,null,6,4,5,null,null,null,null,8,7]
[1,2,3,4,5,6,null,null,null,7,8]
[1,3,2,null,6,4,5,null,null,null,null,8,7,9]
*/

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return true;
        else if(root1 && root2)
        {
            if(root1->val == root2->val)
                return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)
                || flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
            else
                return false;
        }
        return false;
    }
};
