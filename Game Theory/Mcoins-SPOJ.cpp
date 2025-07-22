#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,l,m;
    cin>>k>>l>>m;
    vector<int> v(m,0);
    for(int i=0;i<m;i++) cin>>v[i];
    int limit=*max_element(v.begin(),v.end());
    vector<int> dp(limit+1,0);
    dp[1]=1;
    dp[k]=1;
    dp[l]=1;
    for(int i=2;i<limit+1;i++){
        if(i==k or i==l) continue;
        dp[i]=!(dp[i-1] and (i-k>=1?dp[i-k]:1) and (i-l>=1?dp[i-l]:1));
    }
    
    for(auto i:v) cout<<(dp[i]==0?'B':'A');
    
    
}
