/*200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int land = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '1') {
                   
                    land += 1;
                    erase(grid, i, j);
                }
            }
        }
        return land;
    }

    void erase(vector<vector<char>>& grid, int i, int j) {
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return;
        if (grid[i][j] != '1')
            return;

        grid[i][j] = '0';

        erase(grid, i-1, j);
        erase(grid, i+1, j);
        erase(grid, i, j-1); 
        erase(grid, i, j+1);
        return;
    }
};