/* 1004. Max Consecutive Ones III
Given a binary array nums and an integer k, 
return the maximum number of consecutive 1's in the array if you can flip at most k 0's.*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //find the longest subarray with at most k 0s
        int i=0, zeros=0, j;
        for ( j=0; j<nums.size() ; j++)
        {
            if (nums[j]==0)
                zeros++;
            if (zeros>k)
            {
                if(nums[i]==0)
                    zeros--;
                i++;
            }
        }
        return j-i;
    }
};

/*
For each A[j], try to find the longest subarray.
If A[i] ~ A[j] has zeros <= K, we continue to increment j.
If A[i] ~ A[j] has zeros > K, we increment i (as well as j).
*/