/*96. Unique Binary Search Trees
  Given an integer n, return the number of structurally unique BST's (binary search trees) 
  which has exactly n nodes of unique values from 1 to n.
*/

class Solution {
public:
    int memo[20]{};
    int numTrees(int n) { 
        if (n<=1)
            return 1;
        if(memo[n])
            return memo[n];
        for (int i=1; i<=n; i++){
            memo[n] += numTrees(i-1) * numTrees(n-i);
        }
        return memo[n];
    }
};