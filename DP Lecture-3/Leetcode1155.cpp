#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    const int MOD=1e9+7;
    int f(int n,int k,int target){
        if(target==0 and n==0) return 1;
        if(target==0 or n==0) return 0;
        if(dp[target][n]!=-1) return dp[target][n];
        int count=0;
        for(int i=1;i<=k;i++){
            if(target-i<0) continue;
            count=(count%MOD+f(n-1,k,target-i)%MOD)%MOD;
        }
        return dp[target][n]=count;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.assign(target+1,vector<int> (n+1,-1));
        return f(n,k,target);
    }
};