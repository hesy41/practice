/*113. Path Sum II
  Given the root of a binary tree and an integer targetSum, 
  return all root-to-leaf paths where the sum of the node values in the path equals targetSum. 
  Each path should be returned as a list of the node values, not node references.
  A root-to-leaf path is a path starting from the root and ending at any leaf node. 
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int>path;
        find(root, targetSum, paths, path);
        return paths;
    }
    void find(TreeNode* root, int sum, vector<vector<int>>& paths, vector<int> path){
        if (!root)
            return;
        path.push_back(root->val);
        if(root->val==sum && !(root->right) && !(root->left))
            paths.push_back(path);
        find(root->left, sum-root->val, paths, path);
        find(root->right, sum-root->val, paths, path);
        path.pop_back();
    }
};