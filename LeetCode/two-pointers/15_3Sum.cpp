/*15. 3Sum
  Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size(); i++)
        {
            int front=i+1;
            int back=nums.size()-1;
            
            while (front < back)
            {
                int target = -nums[i];
                int sum = nums[front] + nums[back];
            
                if(sum < target) // need a bigger number
                    front++;
                else if(sum > target) // need a smaller number
                    back--;
                else
                {
                    vector<int> triplets{nums[i], nums[front], nums[back]};
                    ans.push_back(triplets);
                
                    //move the two pointers
                    while(front < back && nums[front] == triplets[1])
                        front ++;
                
                    while(front < back && nums[back] == triplets[2])
                        back--;
                }
            
                while(i+1 <nums.size() && nums[i+1] == nums[i] )
                    i++;
            }
        }
        
        return ans;
        
    }
};

//attempt Jan 5 2023
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty())
            return res;

        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size < 3)
            return res;

        for (int i =0; i < size; i++)
        {
            if(nums[i] > 0)
                break;

            if (i > 0 && nums[i] == nums[i-1])
                continue;

            int target = 0 - nums[i];
            int lo = i+1;
            int hi = size -1;

            while(lo < hi)
            {
                if (nums[lo] + nums[hi] > target)
                    hi--;
                else if (nums[lo] + nums[hi] < target)
                    lo++;
                else
                {
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    int last_lo = nums[lo], last_hi = nums[hi];
                    while(lo < hi && nums[lo] == last_lo)
                        lo++;
                    while(lo < hi && nums[hi] == last_hi)
                        hi--;
                }
            }
        }
        return res;
    }
};