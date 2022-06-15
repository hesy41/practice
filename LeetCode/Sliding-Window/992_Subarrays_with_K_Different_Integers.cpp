/*992. Subarrays with K Different Integers
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.*/

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
    
    int atMost(vector<int>& nums, int k)
    {
        int ans, i=0;
        unordered_map<int, int> count;
        for (int j=0; j<nums.size(); j++)
        {
            if(!count[nums[j]]++)
                k--;
            while(k<0)
            {
                if(!--count[nums[i]])
                    k++;
                i++;
            }
            ans += j-i+1;
        }
        return ans;
    }
};