/* 94. Binary Tree Inorder Traversal
  Given the root of a binary tree, return the inorder traversal of its nodes' values. */

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

//inroder: left-root-right

//recursion solution
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> output;
            print(root,output);
            
            return output;
        }
        
        void print (TreeNode* root, vector<int>& output){
            if (root != nullptr){
                print(root->left, output);
                output.push_back(root->val);
                print(root->right, output);
            }
        }
};

//Morris traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        while (root != nullptr){
            if (root->left == nullptr){
                output.push_back(root->val);
                root = root->right;
            }
            else{
                TreeNode* pre = root->left;
                while (pre->right != nullptr && pre->right != root){
                    pre = pre->right;
                }
                if (pre->right == nullptr){
                    pre->right = root;
                    root = root->left;
                }
                else { //since it is out of the loop
                    //if pre->right still !=null, then pre-right must = root
                    pre->right = nullptr;
                    output.push_back(root->val);
                    root = root->right;
                }
            }
        }
    return output;
    }
};