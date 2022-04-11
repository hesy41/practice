/*654. Maximum Binary Tree
  You are given an integer array nums with no duplicates.
  A maximum binary tree can be built recursively from nums using the following algorithm:
  1. Create a root node whose value is the maximum value in nums.
  2. Recursively build the left subtree on the subarray prefix to the left of the maximum value.
  3. Recursively build the right subtree on the subarray suffix to the right of the maximum value.
  Return the maximum binary tree built from nums.
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> stk;
        for (int num : nums)
        {
            TreeNode* node = new TreeNode(num);
            while(!stk.empty() && stk.top()->val < node->val)
            {
                node->left=stk.top();
                stk.pop();
            }
            if(!stk.empty())
                stk.top()->right=node;
            stk.push(node);
        }
        while(stk.size()>1)
        {
            stk.pop();
        }
        return stk.top();
    }
};