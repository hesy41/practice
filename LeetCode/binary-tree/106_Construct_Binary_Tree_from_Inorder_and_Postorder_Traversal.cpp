/*106. Construct Binary Tree from Inorder and Postorder Traversal*/

#include <iostream>
#include<vector>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
       TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
         
     };

//my oringinal solution: I think it should be able to run on leetcode but somehow it caont
//still dont figure out the reason why
//will try to figure out 
class Solution {
    public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIndex= postorder.size()-1;
        
        return build(inorder, postorder, rootIndex, 0, postorder.size()-1);
    }
    
    TreeNode* build(vector<int>& in, vector<int>& post, int& rootIndex, int left, int right){
        if (right < left)
            return nullptr;
        int pivot=left;

        while (post[rootIndex] != in[pivot])
        {
            pivot++;
        }
           
        rootIndex--;
        TreeNode* root= new TreeNode (in[pivot]);
        root->left = build(in, post, rootIndex, left, pivot-1);
        root->right = build(in, post, rootIndex, pivot+1,right);
        
        return root; 
    }
};

//another solution that can run 
//still dont know the difference between my oringinal one 
class Solution {
public:
    public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n= size(postorder);
        int rootIndx=n-1;
        return build(inorder, postorder, rootIndx,0, n-1);
    }
    
    TreeNode* build(vector<int>& in, vector<int>& post,int& postIdx ,int inStart, int inEnd) {
        if(inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(post[postIdx--]);
        int inIdx = find(begin(in), end(in), root -> val) - begin(in);
        root -> right = build(in, post, postIdx, inIdx+1, inEnd);
        root -> left  = build(in, post, postIdx, inStart, inIdx-1);
        return root;
    }
    
};