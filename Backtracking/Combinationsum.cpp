class Solution {
public:
    vector<vector<int>> result;
    void f(vector<int> &nums,int target,int idx,vector<int> &temp){
        if(target==0){
            result.push_back(temp);
            return;
        }

        for(int i=idx;i<nums.size();i++){
            if(target-nums[i]<0) continue;
            temp.push_back(nums[i]);
            f(nums,target-nums[i],i,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        f(nums,target,0,temp);
        return result;   
    }
};