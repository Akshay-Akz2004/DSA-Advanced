#include<bits/stdc++.h>
class Solution {
public:
    vector<int> dp;
    int f(vector<int> &nums,int idx){
        if(idx==nums.size()-1) return nums[idx];
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int loot=nums[idx]+f(nums,idx+2);
        int notloot=f(nums,idx+1);
        return dp[idx]=max(loot,notloot);
    }
    int rob(vector<int>& nums) {
        dp.assign(nums.size()+1,-1);
        return f(nums,0);
    }
};