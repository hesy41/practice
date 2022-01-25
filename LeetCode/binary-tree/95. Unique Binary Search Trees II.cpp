/*95. Unique Binary Search Trees II
   Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. 
   Return the answer in any order.*/

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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if (n==0)
            return ans;
        else{
            return build(1,n);
        }
    }
    vector<TreeNode*> build(int lo,int hi){
        vector<TreeNode*> ans;
        if (lo>hi)
            ans.push_back(nullptr);
        for (int i=lo; i<=hi; ++i){
            vector<TreeNode*> leftTree=build(lo, i-1);
            vector<TreeNode*> rightTree=build(i+1, hi);
            for (TreeNode* left: leftTree){
                for (TreeNode* right: rightTree){
                    TreeNode* root = new TreeNode(i);
                    root->left=left;
                    root->right=right;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};