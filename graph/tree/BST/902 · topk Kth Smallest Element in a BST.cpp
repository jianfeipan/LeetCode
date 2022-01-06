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
