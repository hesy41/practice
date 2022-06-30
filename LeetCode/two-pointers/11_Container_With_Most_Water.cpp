/*11. Container With Most Water
  You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int water =0;
        while(i<j)
        {
            int h = min (height[j],height[i]);
            water = max (water, (j-i)* h );
            while(height[i]<= h && i<j)
                i++;
            while(height[j]<= h && i<j)
                j--;
        }
        return water;
    }
};