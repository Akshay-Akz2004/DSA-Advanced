
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findWinner(int n, int x, int y) {
        // code here
        vector<int> dp(n+1,0);
        dp[1]=1;
        dp[x]=1;
        dp[y]=1;
        for(int i=2;i<n+1;i++){
            if(i==x or i==y) continue;
            dp[i]=!(dp[i-1] and (i-x>=1?dp[i-x]:1) and (i-y>=1?dp[i-y]:1));
        }
        
        return dp[n];
    }
};
