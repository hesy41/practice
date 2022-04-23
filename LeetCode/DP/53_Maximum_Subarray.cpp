/*53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.
A subarray is a contiguous part of an array.*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int* dp = new int[n];
        dp[0]=nums[0];
        int mx = dp[0];
        
        for (int i=1; i<n; i++)
        {
            dp[i]=nums[i]+ (dp[i-1]>0 ? dp[i-1]:0);
            mx = max(mx, dp[i]);
        }
        
        return mx;
    }
};