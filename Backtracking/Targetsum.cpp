class Solution {
public:
    int count=0;
    void f(vector<int> &nums,int target,int idx){
        if(target==0 and idx==nums.size()){
            count++;
            return;
        }
        if(idx==nums.size()) return;
        f(nums,target-nums[idx],idx+1);
        f(nums,target+nums[idx],idx+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        f(nums,target,0);
        return count; 
    }
};