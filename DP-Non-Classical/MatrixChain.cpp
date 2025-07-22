#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int f(int i,int j,vector<int> &nums){
    if(i==j or i+1==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        ans=min(ans,f(i,k,nums)+f(k,j,nums)+nums[i]*nums[j]*nums[k]);
    }
    return dp[i][j]=ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    dp.assign(1000,vector<int> (1005,-1));
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<(f(0,n-1,v));
}