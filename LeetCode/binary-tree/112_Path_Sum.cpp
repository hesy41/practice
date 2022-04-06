/*112. Path Sum
  Given the root of a binary tree and an integer targetSum, 
  return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
  A leaf is a node with no children.*/

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int ans=0;
        return find(root, targetSum, ans);
    }
    bool find(TreeNode* root, int target, int ans){
        if(!root)
            return false;
        ans=ans+root->val;
        if (ans==target&& !root->left&&!root->right)
           return true;
        return (find(root->left,target,ans)||find(root->right,target, ans));
    }
};

//second solution 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        if(targetSum==root->val&& !root->left && !root->right)
            return true;
      
        return hasPathSum(root->right, targetSum-root->val)||hasPathSum(root->left, targetSum-root->val);
    }
};