#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRow;
    int maxCol;
    vector<vector<int>> dp;
    int f(int row,int col,vector<vector<int>> &grid){
        if(row>maxRow or col>maxCol or grid[row][col]==1) return 0;
        if(row==maxRow and col==maxCol) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        int right=f(row,col+1,grid);
        int down=f(row+1,col,grid);
        return dp[row][col]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        maxRow=grid.size()-1;
        maxCol=grid[0].size()-1;
        dp.assign(maxRow+1,vector<int>(maxCol+1,-1));
        return f(0,0,grid);
    }
};