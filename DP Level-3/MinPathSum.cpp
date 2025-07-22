#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxr,maxc;
    vector<vector<int>> dp;
    int f(int row,int col,vector<vector<int>> &grid){
        if(row>maxr or col>maxc) return INT_MAX;
        if(row==maxr and col==maxc) return grid[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int down=f(row+1,col,grid);
        int right=f(row,col+1,grid);
        return dp[row][col]= grid[row][col]+ min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        maxr=grid.size()-1;
        maxc=grid[0].size()-1;
        dp.assign(maxr+1,vector<int> (maxc+1,-1));
        return f(0,0,grid);
    }
};