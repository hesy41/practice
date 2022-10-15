/*1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

// Oct 15, 2022 attempts
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i=0; i<nums.size()-1; i++)
        {
            int j = i+1;
            while (j<nums.size())
            {
                if(nums[i]+nums[j] != target)
                    j++;
                else
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
            if (! ans.empty())
                break;
        }
        return ans;
    }
};

// May 2, 2022
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i=0; i<nums.size(); i++)
        {
            for (int j=i+1; j<nums.size(); j++)
            {
                if(nums[j]+nums[i]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};