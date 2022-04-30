/*337. House Robber III
The thief has found himself a new place for his thievery again. 
There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, 
the smart thief realized that all houses in this place form a binary tree. 
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.*/

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
    unordered_map<TreeNode*, int> memo;
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        if (memo.count(root))
            return memo[root];
        int noRob=rob(root->left)+rob(root->right);
        int doRob=root->val;//init, add more in the next 
        if(root->left)
            doRob += rob(root->left->left) + rob(root->left->right);
        if(root->right)
            doRob += rob(root->right->left) + rob(root->right->right);
        memo[root]=max(doRob, noRob);
        return memo[root];
        
    }
};