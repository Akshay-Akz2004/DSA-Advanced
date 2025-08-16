class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int row=arr.size();
        int col=arr[0].size();
        vector<vector<int>> dp;
        dp.assign(row,vector<int>(col,0));
        dp[0][0]=arr[0][0];
        dp[0][1]=arr[0][1];
        dp[0][2]=arr[0][2];
        for(int i=1;i<row;i++){
            dp[i][0]=arr[i][0]+max(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=arr[i][1]+max(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=arr[i][2]+max(dp[i-1][1],dp[i-1][0]);
        }
        
        return max({dp[row-1][0],dp[row-1][1],dp[row-1][2]});
    }
};