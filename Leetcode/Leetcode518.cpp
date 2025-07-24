class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<int> &arr,int idx, int target){
        if(target==0) return 1;
        if(dp[idx][target]!=-1) return dp[idx][target];
        int result=0;
        for(int i=idx;i<arr.size();i++){
            if(target-arr[i]<0) continue;
            result+=f(arr,i,target-arr[i]);
        }
        return dp[idx][target]=result;
    }
    int change(int amount, vector<int>& coins) {
        dp.assign(coins.size()+1,vector<int>(amount+1,-1));
        return f(coins,0,amount);
    }
};