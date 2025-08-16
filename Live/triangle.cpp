class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<vector<int>> &nums,int row,int col){
        if(row==nums.size()-1) return nums[row][col];
        if(dp[row][col]!=INT_MAX) return dp[row][col];
        int down=f(nums,row+1,col);
        int downinc=f(nums,row+1,col+1);
        return dp[row][col]=nums[row][col]+min(down,downinc);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        int col=triangle[row-1].size();
        dp.assign(row+1,vector<int> (col+1,INT_MAX));
        return f(triangle,0,0);
    }
};