/*75. Sort Colors
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.*/

 class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return;
    }
};

//solution 2

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int fi=0, hi=nums.size()-1, mi=0;
        while(mi <= hi)
        {
            if(nums[mi] == 0)
            {
                swap(nums[mi], nums[fi]);
                mi++;
                fi++;
            }
            else if(nums[mi]==1)
                mi++;
            else if(nums[mi] ==2)
            {
                swap(nums[mi], nums[hi]);
                hi--;
            }
        }
        return;
    }
};