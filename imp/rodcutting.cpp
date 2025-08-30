// User function Template for C++

class Solution {
  public:
    vector<vector<int>> dp;
    int f(vector<int> &nums,int idx,int len){
        
        if(idx==nums.size() or len==0) return 0;
        if(dp[idx][len]!=-1) return dp[idx][len];
        int case1=0;
        if(len-(idx+1)>=0) case1=nums[idx]+f(nums,idx,len-(idx+1));
        int case2=f(nums,idx+1,len);
        
        return dp[idx][len]=max(case1,case2);
    }
    int cutRod(vector<int> &price) {
        // code here
        dp.assign(price.size(),vector<int> (price.size()+1,-1));
        return f(price,0,price.size());
    }
};