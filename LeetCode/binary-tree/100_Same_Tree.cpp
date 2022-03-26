/*100. Same Tree
  Given the roots of two binary trees p and q, 
  write a function to check if they are the same or not.

  Two binary trees are considered the same if they are structurally identical, 
  and the nodes have the same value.*/

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
    //my first solution
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL && q==NULL)
            return true;
        if (p==NULL && q!=NULL)
            return false;
        if (p!=NULL && q==NULL)
            return false;
        
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    //my second solution 
     bool isSameTree(TreeNode* p, TreeNode* q) {
        //checking whether q and p are the same in turns of 
        //the being null or not
        if (p==NULL || q==NULL)
            return (p==q);
        //chekcing whether the val is the same
        if (p->val != q->val)
            return false;
        
        //recursively finding in both right and left
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};