/*35. Search Insert Position
  Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int fi=0, la=nums.size()-1;
        while(fi<=la)
        {
            int mid=(fi+la)/2;
            if (target==nums[mid])
                return mid;
            else if(target>nums[mid])
                fi=mid+1;
            else
                la=mid-1;
        }
        return fi;
    }
    
};