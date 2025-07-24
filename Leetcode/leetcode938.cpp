class Solution {
public:
    vector<int> dp;
    int f(vector<int> &arr,vector<int> &cost,int idx){
        if(idx==arr.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int case1=cost[0]+f(arr,cost,idx+1);
        //case2
        int count=0;
        for(int i=idx;i<arr.size();i++){
            if(arr[i]<arr[idx]+7) count++;
            else break;
        }
        int case2=cost[1]+f(arr,cost,idx+count);

        //case3
        count=0;
        for(int i=idx;i<arr.size();i++){
            if(arr[i]<arr[idx]+30) count++;
            else break;
        }
        int case3=cost[2]+f(arr,cost,idx+count);
        return dp[idx]=min({case1,case2,case3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        dp.assign(n+1,-1);
        return f(days,costs,0);      
    }
};