/*107. Binary Tree Level Order Traversal II
   Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. 
   (i.e., from left to right, level by level from leaf to root).*/


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

//a cheating solution which may not be accepted during interview lol....
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int depth=0;
        build(root, depth); 
        reverse(ans.begin(),ans.end()); //simply use the reverse function to make it bottom-up...
        return ans;
    }
    
     void build(TreeNode* root, int depth){
        if (root == NULL)
            return ;
        
        if (ans.size()==depth)
            ans.push_back(vector<int>());
         ans[depth].push_back(root->val);
         build(root->left, depth+1);
         build(root->right, depth+1);
         
         
            
    }
};

class Solution {
public:
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int depth = dep(root);
        //initialize the vector with enough space for each level
        vector<vector<int>> ans(depth, vector<int>{});
        //here we need depth-1 since in the later function depth are use as the vector index
        build (root, depth-1, ans);
        return ans;
    }
    
    void build(TreeNode* root, int depth, vector<vector<int>>& ans){
        if (root==NULL)
            return;
        ans[depth].push_back(root->val);
        //build left subtree first since the problem require from left to right
        build(root->left, depth-1, ans);
        build(root->right, depth-1, ans);
    }
    
    int dep(TreeNode* root){
        if (root==NULL)
            return 0;
        return max(dep(root->left),dep(root->right))+1;
    }
    
};

