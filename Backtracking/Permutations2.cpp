class Solution {
public:
    vector<vector<int>> result;
    void f(vector<int> &nums,int idx){
        if(idx==nums.size()){
            result.push_back(nums);
            return;
        }
        unordered_map<int,bool> mp;
        for(int i=idx;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()) continue;
            mp[nums[i]]=true;
            swap(nums[i],nums[idx]);
            f(nums,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        f(nums,0);
        return result;
    }
};