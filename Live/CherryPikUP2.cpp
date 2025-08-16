class Solution {
public:
    int maxrow;
    int maxcol;
    vector<vector<vector<int>>> dp;
    
    int f(vector<vector<int>> &grid,int row,int col1,int col2){
        if(col1>=maxcol or col2>=maxcol or col1<0 or col2<0 or row>=maxrow) return INT_MIN;
        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];
        if(row==maxrow-1){
            if(col1==col2) return grid[row][col1];
            return grid[row][col1]+grid[row][col2];
        }

        int cherry=grid[row][col1];
        if(col1!=col2) cherry+=grid[row][col2];

        int best=max({
            f(grid,row+1,col1-1,col2-1),
            f(grid,row+1,col1,col2),
            f(grid,row+1,col1+1,col2+1),
            f(grid,row+1,col1+1,col2),
            f(grid,row+1,col1+1,col2-1),
            f(grid,row+1,col1,col2+1),
            f(grid,row+1,col1,col2-1),
            f(grid,row+1,col1-1,col2),
            f(grid,row+1,col1-1,col2+1),
        });

        cherry+=best;
        return dp[row][col1][col2]=cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        maxrow=grid.size();
        maxcol=grid[0].size();
        dp.assign(maxrow+1,vector<vector<int>> (maxcol+1,vector<int> (maxcol+1,-1)));
        return f(grid,0,0,maxcol-1);
    }
};