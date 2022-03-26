/*101. Symmetric Tree
  Given the root of a binary tree, 
  check whether it is a mirror of itself (i.e., symmetric around its center).
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
    bool isSymmetric(TreeNode* root) {
        if (root==NULL)
            return true;
        return Sametree(root->left, root->right);
    }
    
    bool Sametree(TreeNode* p, TreeNode* q){
        if (p==NULL || q==NULL)
            return (p==q);
        //chekcing whether the val is the same
        if (p->val != q->val)
            return false;
        
        //mirroring 
        return Sametree(p->left, q->right) && Sametree(p->right, q->left);
    }
};