/*18. 4Sum
  Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        if(n<4)
            return ans;
        sort(nums.begin(), nums.end());
        if(target<0 && nums[0]>0)
            return ans;
        for (int i=0; i<n-3; i++)
        {
            if(i>0 && nums[i]==nums[i-1]) // same as the pervioous one 
                continue;
            if(nums[i]+nums[i+1] > target - nums[i+2] - nums[i+3]) // smallest combo for i and larger
                break;
            if(nums[i]+nums[n-3] < target - nums[n-2] - nums[n-1])//biggest combo for i
                continue;
            
            for(int j=i+1; j<n-2; j++)
            {
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                if(nums[i]+nums[j]>target-nums[i+2]-nums[i+3])
                    break;
                if(nums[i]+nums[j]<target-nums[n-1]-nums[n-2])
                    continue;
                int left=j+1, right = n-1;
                while(left<right)
                {
                    if(nums[left] + nums[right] > target - nums[i] - nums[j])
                        right--;
                    else if(nums[left] + nums[right] < target - nums[i] - nums[j])
                        left ++;
                    else{
                        /*vector<int> quadruplets{nums[i], nums[j], nums[left], nums[right]};
                        ans.push_back(quadruplets);*/
                        ans.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        do{left++;}
                        while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}
                        while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return ans;
    }
};