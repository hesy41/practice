/*652. Find Duplicate Subtrees
Given the root of a binary tree, return all duplicate subtrees.
For each kind of duplicate subtrees, you only need to return the root node of any one of them. 
Two trees are duplicate if they have the same structure with the same node values.*/

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string, int> map;
        string s=find(root, ans, map);
        return ans;
    }
    
    string find(TreeNode* root, vector<TreeNode*>& ans, unordered_map<string, int>& map)
    {
        if(!root)
            return " ";
        string s= to_string(root->val)+ " "+ find(root->left, ans, map)+find(root->right, ans, map);
        if (map[s]++==1)
            ans.push_back(root);
        return s;
    }
};