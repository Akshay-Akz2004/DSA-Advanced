class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<int> &arr,int idx,int target){
        if(target==0) return true;
        if(idx==arr.size() or target<0) return false;
        if(dp[idx][target]!=-1) return dp[idx][target];
        int take=f(arr,idx+1,target-arr[idx]);
        int skip=f(arr,idx+1,target);
        return dp[idx][target]=take or skip;
    }
    bool canPartition(vector<int>& nums) {
           int target=0;
           for(auto i:nums) target+=i;
           if(target%2==1) return false;
           dp.assign(nums.size()+1,vector<int>((target/2)+2,-1));
           return f(nums,0,target/2);
    }
};