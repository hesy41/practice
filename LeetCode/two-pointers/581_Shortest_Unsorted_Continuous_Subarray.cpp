/*581. Shortest Unsorted Continuous Subarray
   Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size(), ma=nums[0], mi=nums[n-1], beg=-1, end=-2;
        for(int i=1; i<n; i++) 
        {
            ma=max(ma, nums[i]);
            mi= min(mi, nums[n-i-1]);
            if(nums[i] < ma)
                end=i;
            if(nums[n-1-i] > mi) 
                beg=n-1-i;
        }
        return end-beg+1;
    }
};