/*144. Binary Tree Preorder Traversal
  Given the root of a binary tree, return the preorder traversal of its nodes' values.*/

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

//recursive solution 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        build(root, ans);
        return ans;
    }
    void build(TreeNode* root, vector<int>& ans)
    {
        if(!root)
            return;
        ans.push_back(root->val);
        build(root->left, ans);
        build(root->right, ans);
    }
};