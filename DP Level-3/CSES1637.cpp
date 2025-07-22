#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
int f(int n){
    if(n<=9) return 1;
    if(dp[n]!=-1) return dp[n];
    int res=INT_MAX;
    for(auto i:to_string(n)){
        int val=i-'0';
        if(val==0) continue; 
        res=min(res,f(n-val));
    }
    
    return dp[n]=res+1;
}
int main(){
    int n;
    cin>>n;
    dp.assign(n+1,-1);
    cout<<f(n);
}