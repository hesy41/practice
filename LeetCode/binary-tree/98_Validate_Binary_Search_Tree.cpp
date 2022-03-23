/*98. Validate Binary Search Tree
  Given the root of a binary tree, determine if it is a valid binary search tree (BST).
  A valid BST is defined as follows:
    
    The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
    TreeNode* prev = NULL;
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        if (! isValidBST(root->left))
            return false;
        if (prev != NULL && prev->val >= root->val)
            return false;
        prev = root;
        if (! isValidBST(root->right))
            return false;
        
        return true;
    }
};

//here we use an in-order thought.
//we traverse to the left most node of the tree which should contain the smallest val in the whole tree.
//And with in-order thought, everything after should be greater than the prev.