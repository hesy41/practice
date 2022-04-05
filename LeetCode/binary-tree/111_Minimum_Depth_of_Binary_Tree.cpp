/*111. Minimum Depth of Binary Tree
  Given a binary tree, find its minimum depth.
  The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
  Note: A leaf is a node with no children.*/

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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int i=0;
        while (!Q.empty())
        {
            i++;
            int k = Q.size();
            for (int j=0; j<k; j++)
            {
                TreeNode* rt=Q.front();
                if(rt->right)
                    Q.push(rt->right);
                if(rt->left)
                    Q.push(rt->left);
                Q.pop();
                if (!rt->left && !rt->right)
                    return i;
            }
        }
        return -1; //to fill in the return place
    }

};