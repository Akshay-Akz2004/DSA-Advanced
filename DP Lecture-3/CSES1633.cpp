#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
const int MOD=1e9+7;
int f(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    int count=0;
    for(int i=1;i<=6;i++){
        count=(count+f(n-i))%MOD;
    }
    
    return dp[n]=count;
}
int main(){
    int n;
    cin>>n;
    dp.assign(n+1,-1);
    cout<<f(n);
}