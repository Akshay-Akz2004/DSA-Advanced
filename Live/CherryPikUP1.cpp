class Solution {
public:
    int n;
    vector<vector<vector<vector<int>>>> dp;

    int f(vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return INT_MIN;
        }

        if (r1 == n-1 && c1 == n-1) return grid[r1][c1];
        if (dp[r1][c1][r2][c2] != INT_MIN) return dp[r1][c1][r2][c2];
        int cherries = grid[r1][c1];
        if (!(r1 == r2 && c1 == c2)) {
            cherries += grid[r2][c2]; 
        }

        int best = max({
            f(grid, r1+1, c1, r2+1, c2),   
            f(grid, r1, c1+1, r2, c2+1),  
            f(grid, r1+1, c1, r2, c2+1),   
            f(grid, r1, c1+1, r2+1, c2)    
        });

        cherries += best;
        return dp[r1][c1][r2][c2] = cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        dp.assign(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, INT_MIN))));
        return max(0, f(grid, 0, 0, 0, 0));
    }
};
