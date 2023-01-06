/*16. 3Sum Closest
  Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-2; i++)
        {
            int front = i+1;
            int last = n-1;
            
            while (front < last)
            {
                int sum= nums[i] + nums[front] + nums[last];
                if(sum==target)
                    return sum;
                
                if(abs(sum-target) < abs(ans-target))
                    ans=sum;
                if(sum > target)
                    last--;
                else 
                    front++;
            }
        }
        return ans;
    }
};

// attempt Jan 6 2023
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0]+nums[1]+nums[2];
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=0; i<n-2; i++)
        {
            int lo = i+1, hi = n-1;
            while(lo < hi)
            {
                int sum = nums[i]+nums[lo]+nums[hi];
                if (sum == target)
                    return sum;
                if (abs(sum - target) < abs(ans - target))
                    ans = sum;
                if (sum > target)
                    --hi;
                else
                    ++lo;                
            }
        }
        return ans;
    }
};