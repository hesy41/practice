/*55. Jump Game
You are given an integer array nums. You are initially positioned at the array's first index,
 and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable =0;
        for (int i=0; i<nums.size()-1; i++)
        {
            maxReachable = max(maxReachable, i+nums[i]);
            if(maxReachable <= i)
                return false;
        }
        return maxReachable >=nums.size()-1;
    }
};