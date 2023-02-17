/*783. Minimum Distance Between BST Nodes*/

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
    int minDiffInBST(TreeNode* root) {
        vector <int> arr;
        convert(arr, root);
        sort(arr.begin(), arr.end());
        int min = INT_MAX;
        for (int i=0; i<arr.size()-1; i++) {
            if(arr[i+1]-arr[i] < min)
                min = arr[i+1]-arr[i];
        }
        return min;
    }

    void convert (vector<int>& arr, TreeNode* root) {
        if (!root)
            return;
        arr.push_back(root->val);
        convert(arr, root->right);
        convert(arr, root->left);
    }
};