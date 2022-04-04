/*110. Balanced Binary Tree
 Given a binary tree, determine if it is height-balanced.
 For this problem, a height-balanced binary tree is defined as:
 a binary tree in which the left and right subtrees of every node differ in height by no more than 1.*/

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
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        int left=height(root->left);
        int right=height(root->right);
        if(max(left,right)-min(left,right)>1)
            return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return max(height(root->right), height(root->left))+1;
    }
};