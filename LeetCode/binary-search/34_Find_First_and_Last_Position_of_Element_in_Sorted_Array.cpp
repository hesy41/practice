/*34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int n = nums.size();
        int i=0;
        int j=n-1;
        
        if (n==0)
            return ans;
        
        //left bound
        while(i<j)
        {
            int mid = (i+j)/2;
            if(nums[mid]<target) //left bound on the right of mid
                i = mid+1;
            else
                j=mid;
        }
        if (nums[i]!=target)//not found
            return ans;
        else
            ans[0]=i;
        

        //right bound
        j=n-1; // restart j to find the right bound
        while(i<j)
        {
            int mid = (i+j)/2 + 1;
            if(nums[mid]>target)
                j=mid-1;
            else
                i=mid;
        }
        ans[1]=j;
        return ans;
    }
};