/*219. Contains Duplicate II
  Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.*/
  class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> rec;
        for (int j=0; j<nums.size(); j++)
        {
            if(rec.count(nums[j])==0)
                rec[nums[j]] = j;
            else
            {
                if(j- rec[nums[j]] <= k)
                    return true;
                else
                    rec[nums[j]]=j;
            }
        }
        return false;
    }
};