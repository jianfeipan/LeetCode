/*
Given the root of a non-empty binary tree, return the maximum path sum of any non-empty path.

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes has an edge connecting them. A node can not appear in the sequence more than once. The path does not necessarily need to include the root.

The path sum of a path is the sum of the node's values in the path.

Example 1:



Input: root = [1,2,3]

Output: 6
Explanation: The path is 2 -> 1 -> 3 with a sum of 2 + 1 + 3 = 6.

Example 2:



Input: root = [-15,10,20,null,null,15,5,-5]

Output: 40
Explanation: The path is 15 -> 20 -> 5 with a sum of 15 + 20 + 5 = 40.

Constraints:

1 <= The number of nodes in the tree <= 1000.
-1000 <= Node.val <= 1000

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

class Solution 
{
/*
facts:
    1.one node can be taken or not, we don't neccessarily from leaf to leaf
    2.for any path, the "identity" of the path is the root
    3. node val can be negative -> std::max(0, 
idae:
    1 recursivly traversal all nodes, compute the max sum to it's leaf

complexity:
time O(n)
stack usage O(n)


    */
private:
int d_maxSum = INT_MIN;
int _maxToLeaf(TreeNode* node) 
{
    if(!node) return 0;
    auto leftMax = _maxToLeaf(node->left); 
    auto rightMax = _maxToLeaf(node->right); 
    d_maxSum = std::max(d_maxSum, node->val + std::max(0, leftMax) + std::max(0, rightMax));// this is running on all nodes we make use of this to update maxSum
    return node->val + std::max(0, std::max(leftMax, rightMax));

}


public:  
int maxPathSum(TreeNode* root) 
{
    if(root == nullptr) return 0; 
    // max if from left to a leaf
    auto leftMax = _maxToLeaf(root->left); 
    // right
    auto rightMax = _maxToLeaf(root->right); 

    d_maxSum = std::max(d_maxSum, root->val + std::max(0, leftMax) + std::max(0, rightMax));

    return d_maxSum;
}

};
