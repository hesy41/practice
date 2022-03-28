/*103. Binary Tree Zigzag Level Order Traversal
   Given the root of a binary tree, 
   return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root==NULL)
            return result;
        
        queue<TreeNode*> nodesQ;
        nodesQ.push(root);
        bool left2right=true;
        
        while (!nodesQ.empty())
        {
            int size = nodesQ.size();
            vector<int> row(size);
            for (int i=0; i<size; i++)
            {
                TreeNode* node = nodesQ.front();
                nodesQ.pop();
            
                int index=(left2right) ? i : (size - 1 - i);
            
                row[index]=node->val;
                if (node->left) {
                    nodesQ.push(node->left);
                }
                if (node->right) {
                    nodesQ.push(node->right);
                }
            }
            left2right = !left2right;
            result.push_back(row);
        }
        
        return result;
    }
};

//another great solution
//https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/787/discuss/1539875/c++-Simple-code-using-2-stacks-O(n)