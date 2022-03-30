/*105. Construct Binary Tree from Preorder and Inorder Traversal
  Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree 
  and inorder is the inorder traversal of the same tree, construct and return the binary tree.*/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIndex=0;
        return build(preorder, inorder, rootIndex, 0, preorder.size()-1 );
        }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIndex, int left, int right){
        if (right<left)
            return NULL;
        int pivot=left;
        while (preorder[rootIndex]!=inorder[pivot]){
            pivot++;
        }
        rootIndex++;
        TreeNode* newNode= new TreeNode (inorder[pivot]);
        newNode->left=build(preorder, inorder, rootIndex, left, pivot-1);
        newNode->right=build(preorder, inorder, rootIndex, pivot+1, right);
        return newNode;
    }
};