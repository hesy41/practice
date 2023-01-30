/*733. Flood Fill
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target = image[sr][sc];
        if (target == color)
            return image;
        
        fill(image, sr, sc, color, target);
        return image;
    }
    void fill(vector<vector<int>>& image, int sr, int sc, int color, int target) {
        if (sr <0 || sc <0 || sr>=image.size() || sc>=image[0].size())
            return;
        if(image[sr][sc] != target)
            return;
        
        image[sr][sc] = color;
        fill(image, sr-1, sc, color, target);
        fill(image, sr+1, sc, color, target);
        fill(image, sr, sc-1, color, target);
        fill(image, sr, sc+1, color, target);
        return;
    }
};