class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        int total = m*n;
        k %= total;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int ind = i*n + j;
                int newInd = (ind+k)%total;
                res[newInd/n][newInd%n] = grid[i][j];
            }
        }
        return res;
    }
};