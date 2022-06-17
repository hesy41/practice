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