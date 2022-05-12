/*209. Minimum Size Subarray Sum
  Given an array of positive integers nums and a positive integer target, 
  return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. 
  If there is no such subarray, return 0 instead.
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int r=0, l=0, len=INT_MAX, n=nums.size(), sum=0;
        while (r<n)
        {
            sum += nums[r++];
            while(sum>=target)
            {
                len = min(len, r-l);
                sum -= nums[l++];
            } 
        }
        return len==INT_MAX ? 0:len;
            
    }
};