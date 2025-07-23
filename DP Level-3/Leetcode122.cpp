class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<int> &prices,int idx,bool flag){
        if(idx==prices.size()) return 0;
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        if(flag==true){
            int case1=f(prices,idx+1,flag);
            int case2=-prices[idx]+f(prices,idx+1,!flag);
            return dp[idx][flag]= max(case1,case2);
        }
        else{
            int case1=f(prices,idx+1,flag);
            int case2=prices[idx]+f(prices,idx+1,!flag);
            return dp[idx][flag]=max(case1,case2);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.assign(n+1,vector<int> (2,-1));
        return f(prices,0,true);
    }
};