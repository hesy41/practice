/*108. Convert Sorted Array to Binary Search Tree
Given an integer array nums where the elements are sorted in ascending order, 
convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which 
the depth of the two subtrees of every node never differs by more than one.*/

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size=nums.size();
        if (size==0)
            return NULL;
        if (size==1)
            return new TreeNode(nums[0]);
        int mid=size/2;
        
        TreeNode* root=new TreeNode(nums[mid]);
        
        vector<int> left(nums.begin(), nums.begin()+mid);
        vector<int> right(nums.begin()+mid+1, nums.end());
        
        root->left=sortedArrayToBST(left);
        root->right=sortedArrayToBST(right);
        
        return root;
    }
    
};