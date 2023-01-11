/*
724. Find Pivot Index
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivot = -1, n = nums.size();
        //calculate the sum of all elements in nums
        int sum = nums[0];
        for (int i = 1; i<n; ++i)
        {
            sum += nums[i];
        }

        //find the left-most pivot
        int leftsum = 0, rightsum = sum - nums[0];
        for (int j=0; j<n; ++j)
        {
            if (leftsum == rightsum)
            {
                pivot = j;
                break;
            }
            else
            {
                leftsum += nums[j];
                rightsum -= j==n-1 ? 0: nums[j+1];
            }
        }
        return pivot;
    }
};