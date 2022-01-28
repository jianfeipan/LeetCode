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

/*
You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.

failed test: 
Input
[0,3,1,null,null,null,1,null,0]
Output
7
Expected
5
*/
class Solution 
{
public:
    int distributeCoins(TreeNode* root) 
    {
        if(root)
        {
            if(root->left && root->right)
            {
                pair<int, int> leftTree = countTree(root->left);
                const int leftNeed = leftTree.first - leftTree.second;
                
                pair<int, int> rightTree = countTree(root->right);
                 const int rightNeed = rightTree.first - rightTree.second;
                
                
                const int stepsNeededOnRoot = abs(leftNeed) + abs(1 + leftNeed - root->val);
                    
                    // (leftNeed - root->val + 1)/*root need get from right*/
                     //  leftNeed/*then give left what left needs*/;
                
                //update nodes
                root->left->val+= leftNeed;//left get what he needed;
                root->right->val+=rightNeed;
                root->val = 1;
                
                const int leftSteps = distributeCoins(root->left);
                const int rightSteps = distributeCoins(root->right);
                
                return leftSteps+ rightSteps + abs(stepsNeededOnRoot);
            }
            else if(root->left || root->right)
            {
                const int rootNeed = 1 - root->val;
                
                
                //give all rest to left or right since only one child
                root->val = 1;
                
                TreeNode * child = root->left? root->left : root->right;
                
                child->val -= rootNeed;
                
                const int childSteps = distributeCoins(child);
                
                return childSteps + abs(rootNeed);
            }
            else
            {
                return 0;
            }
            
        }
        return 0;
    }
    
private:
    //count nodes number and coins number
    pair<int, int> countTree(TreeNode* root)
    {
        if(root)
        {
            pair<int, int> left = countTree(root->left);
            pair<int, int> right = countTree(root->right);
            
            return {left.first+right.first +1, left.second+right.second + root->val};
        }
        return {0, 0};
    }
};
