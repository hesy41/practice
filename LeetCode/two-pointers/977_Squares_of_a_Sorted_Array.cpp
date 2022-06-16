/*977. Squares of a Sorted Array
  Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans (nums.size());
        int i=0, j=nums.size()-1;
        for(int k=ans.size()-1; k >=0; k--)
        {
            if(abs(nums[i]) > abs(nums[j]))
                ans[k]= nums[i] * nums[i++];
            else
                ans[k] = nums[j] * nums[j--];
        }
        return ans;
    }
};