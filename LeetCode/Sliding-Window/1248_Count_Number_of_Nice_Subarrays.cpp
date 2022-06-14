/*1248. Count Number of Nice Subarrays
  Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        //Exactly K times = at most K times - at most K - 1 times
        return atMost(nums, k) - atMost(nums,k-1);
    }
    
    int atMost(vector<int>& nums, int k)
    {
        int i=0, ans=0;
        for(int j=0; j<nums.size(); j++)
        {
            k -= nums[j]%2;
            while( k< 0) //at most k times
            {
                k+=nums[i++]%2;
            }
            ans +=j-i+1;
        }
        return ans;
    }
};