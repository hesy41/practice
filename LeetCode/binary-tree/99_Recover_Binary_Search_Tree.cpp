/* 99. Recover Binary Search Tree
   You are given the root of a binary search tree (BST),
   where the values of exactly two nodes of the tree were swapped by mistake. 
   Recover the tree without changing its structure.

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
    TreeNode* first = NULL;
    TreeNode* second= NULL;
    TreeNode* prev=NULL;
    void recoverTree(TreeNode* root) {
        //call in-order to find the 2 invalid node
        in_order(root);
        
        //swap the two invaild nodes
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    
    void in_order(TreeNode* root){
        if (root == NULL)
            return;
        in_order(root->left);
        
        //DIY part
        if (prev!=NULL && first==NULL && prev->val>=root->val)
            first = prev;
        if (first != NULL && prev->val>=root->val)
            second =root;
        // if there is just 2 constructive ones that need to swap
        //it would be like this.
        //and second pointer might be update later if there is another invaild node
        prev=root;
        
        in_order(root->right);
    }
};

// also in-order thought 