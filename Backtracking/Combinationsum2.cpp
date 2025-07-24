class Solution {
public:
    vector<vector<int>> result;
    void f(vector<int> &nums,int target,int idx,vector<int> &temp){
        if(target==0){
            result.push_back(temp);
            return;
        }
        unordered_map<int,bool> mp;
        for(int i=idx;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()) continue;
            if(target-nums[i]<0) continue;
            mp[nums[i]]=true;
            temp.push_back(nums[i]);
            f(nums,target-nums[i],i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        f(nums,target,0,temp);
        return result;
    }
};