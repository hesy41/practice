/*1020. Number of Enclaves*/
class Solution {
public:
    int numEnclaves(vector<vector<int>>& g) {
        int num = 0;
        int m = g.size();
        int n= g[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i*j==0 || i==m-1 || j==n-1) {
                    if(g[i][j]==1)
                        int temp = fill(g, i, j);
                }
            }
        }
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if(g[i][j]==1)
                    num += fill(g, i, j);
            }
        }
        return num;
    }

    int fill(vector<vector<int>>& g, int i, int j) {
        if(i<0 || j<0 || i>=g.size() || j>=g[0].size()) 
            return 0;
        if(g[i][j] != 1)
            return 0;
        
        g[i][j] = 0;

        return (1+fill(g,i+1,j)+fill(g,i-1,j)+fill(g,i,j-1)+fill(g,i,j+1));
    }
};