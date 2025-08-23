class Solution {
public:
    vector<int> dp;
    int f(vector<int> &nums,int idx){
        if(idx==nums.size()-1) return 0;
        if(idx>=nums.size()) return 1e8;
        if(dp[idx]!=-1) return dp[idx];
        int minjump=1e8;
        for(int i=1;i<=nums[idx];i++){
            minjump=min(minjump,f(nums,idx+i));
        }
        return dp[idx]=1+minjump;
    }
    int jump(vector<int>& nums) {
        dp.assign(nums.size()+1,-1);
        return f(nums,0);
    }
};