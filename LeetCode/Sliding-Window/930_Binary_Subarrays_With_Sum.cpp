/*930. Binary Subarrays With Sum
 Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //Exactly K times = at most K times - at most K - 1 times
        return atMost(nums, goal)-atMost(nums,goal-1);
    }
    int atMost(vector<int>& nums, int goal)
    {
        if (goal <0)
            return 0;
        int ans=0, i=0;
        for(int j=0; j<nums.size(); j++)
        {
            goal-=nums[j];
            while(goal<0) // atmost goal
            {
                goal += nums[i++];
                
            }
            ans+=j-i+1;
        }
        return ans;
        
    }
};