/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

/*

Description
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?


- can we make change of the BST modifications？ K is a more static value, I mean we can design the tree as a tree with left side always have K element, so every time the kth smallest is the root
when you do remove or insertion, just make sure the insertion and remove make the rotation of the root to keep k element on left.

good: quick access the kth smallest number
bad : tree is not well balanced and impact the efficiety of search

- we can add a count number in the node: to count the index from left, insert and remove will update these count in node.

*/

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        //Idea: small-to-big traversal of the BST : inorder traversal, use a counter to reach K
        int result = -1;
        inOrderTraversal(root, k , result);

        return result;
     }

private:
    int inOrderTraversal(TreeNode * root, int k, int & result)
    {
        if(root)
        {
            k = inOrderTraversal(root->left, k, result);
            
            if(k>0)
            {
                --k;
                if(k==0)
                {
                    result = root->val;
                }

                k = inOrderTraversal(root->right, k, result);
            }
        }
        return k;
    }
};
