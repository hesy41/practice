/*45. Jump Game II
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(), 10001);
        //memo[i] will store at th)e i-th index of num, the min number of jump needed 
        return solve(nums, memo, 0);
    }
    
    //recursive memorization
    int solve(vector<int>& nums, vector<int>& memo, int pos)
    {
        //already convered the last index, dont need any jump at all
        if(pos >= nums.size()-1)
            return 0;
        
        if (memo[pos] != 10001)
            return memo[pos];
        
        
        for(int i=1; i<=nums[pos]; i++)
        {
            memo[pos] = min (memo[pos] , solve(nums, memo, pos + i)+1);
        }
        
        return memo[pos];
    }
};