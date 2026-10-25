class Solution {
private:
    int m, n;
    bool closed(vector<vector<int>>& grid, int i, int j) {  
        if (i < 0 || i >= m || j < 0 || j >= n) return false;  // stepped off the grid: the island touches the border
        if (grid[i][j]) return true;  // water, or land we already flooded
        grid[i][j] = 1;  // visited: turn it into water
        return closed(grid, i + 1, j) & closed(grid, i - 1, j) & closed(grid, i, j + 1) & closed(grid, i, j - 1); 
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++)
                if (!grid[i][j]) count += closed(grid, i, j);
        }
        return count;
    }
};