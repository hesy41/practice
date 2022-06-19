/*713. Subarray Product Less Than K
  Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) { 
        if(k==0)
            return 0;
        
        int ans=0, prod=1;
        for (int i=0, j=0; j<nums.size();j++)
        {
            prod *= nums[j];
            while (i<=j && prod >=k)
            {
                prod/=nums[i];
                i++;
            }
            ans += j-i+1;
            
        }
        return ans;
    }
};