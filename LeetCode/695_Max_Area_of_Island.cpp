/*695. Max Area of Island
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    earse (grid, i, j, count);
                    max = count>max? count:max;
                }
            }
        }
        return max;
    }
    void earse (vector<vector<int>>& grid, int i, int j, int& count) {
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return;
        if (grid[i][j] == 0)
            return;

        grid[i][j] = 0;
        count +=1;

        earse (grid, i+1, j, count);
        earse (grid, i-1, j, count);
        earse (grid, i, j+1, count);
        earse (grid, i, j-1, count);
        return;
    }
};