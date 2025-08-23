class Solution {
public:
    vector<int> dp;
    int f(vector<int> &nums,int idx){
        if(idx==nums.size()-1) return true;
        if(idx>=nums.size()) return false;
        if(dp[idx]!=-1) return dp[idx];
        bool canreach=false;
        for(int i=1;i<=nums[idx];i++){
            canreach=f(nums,idx+i);
            if(canreach) break;
        }

        return dp[idx]=canreach;
    }
    bool canJump(vector<int>& nums) {
        dp.assign(nums.size()+1,-1);
        return f(nums,0);
    }
};