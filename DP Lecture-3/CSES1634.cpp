#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
int f(vector<int> &nums,int target){
    if(target==0) return 0;
    if(dp[target]!=-1) return dp[target];
    int res=INT_MAX;
    for(auto i:nums){
        if(target-i<0) continue;
        res=min(res,f(nums,target-i));
    }
    
    if(res==INT_MAX) return dp[target]=INT_MAX;
    return dp[target]=res+1;
}
int main(){
    int n;
    int x;
    cin>>n>>x;
    dp.assign(x+1,-1);
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    int ans=(f(nums,x)==INT_MAX) ? -1 : f(nums,x);
    cout<<ans;
}