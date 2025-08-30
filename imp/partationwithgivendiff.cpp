class Solution {
  public:
    vector<vector<int>> dp;
    int f(vector<int> &arr,int target,int idx){
        
        if(idx==arr.size()){
            if(target==0) return 1;
            return 0;
        } 
        if(dp[idx][target]!=-1) return dp[idx][target];
        int take=0;
        if(target-arr[idx]>=0) take=f(arr,target-arr[idx],idx+1);
        int nottake=f(arr,target,idx+1);
        return dp[idx][target]=take+nottake;
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int sum=0;
        for(auto i:arr) sum+=i;
        int temp=sum+d;
        if(temp%2==1) return 0;
        
        
        int target=temp/2;
        dp.assign(arr.size(),vector<int> (target+1,-1));
        return f(arr,target,0);
    }
};