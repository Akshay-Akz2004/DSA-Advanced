class Solution {
  public:
    vector<vector<int>> dp;
    bool f(vector<int> &arr,int sum,int idx){
        if(sum==0) return true;
        if(arr.size()==idx or sum<0) return false;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int take=f(arr,sum-arr[idx],idx+1);
        int skip=f(arr,sum,idx+1);
        return dp[idx][sum]=take or skip;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        dp.assign(n+1,vector<int> (sum+1,-1));
        return f(arr,sum,0);
    }
};