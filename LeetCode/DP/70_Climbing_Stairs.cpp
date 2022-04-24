/*70. Climbing Stairs
  You are climbing a staircase. It takes n steps to reach the top.
  Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?*/

class Solution {
public:
    //the distinct way for climbing to n steps is the sum of climbing to n-1 and n-2
    int* memo;
    int climbStairs(int n) {
        memo = new int[n+1];
        return dp(n);
    }
    int dp(int n)
    {
        if (n<=2)
            return n;
        if(memo[n]>0)
            return memo[n];
        memo[n]=dp(n-1)+ dp(n-2);
        return memo[n];
    }
};