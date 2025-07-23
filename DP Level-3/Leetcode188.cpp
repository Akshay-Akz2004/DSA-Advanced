class Solution {
public:
    int dp[1005][105][2];
    int f(int k,vector<int> &prices,int idx,bool flag){
        if(idx==prices.size()) return 0;
        if(dp[idx][k][flag]!=-1) return dp[idx][k][flag];
        int case1=f(k,prices,idx+1,flag);
        int case2=(flag==true and k>0?-prices[idx]+f(k-1,prices,idx+1,!flag):INT_MIN);
        int case3=(flag==false?prices[idx]+f(k,prices,idx+1,!flag):INT_MIN);
        return dp[idx][k][flag]=max({case1,case2,case3});
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(k,prices,0,true);
    }
};