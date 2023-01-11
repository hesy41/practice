/*
1480. Running Sum of 1d Array
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Return the running sum of nums.
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector <int> ans;
        ans.push_back(nums[0]);
        int size = nums.size();
        for (int i=1; i<size; i++)
        {
            int sum = nums[i]+ans[i-1];
            ans.push_back(sum);
        }
        return ans;
    }
};