class Solution {
public:
    vector<vector<int>> result;
    void f(vector<int> &nums,int idx,vector<int> &temp){
        if(temp.size()>=2) result.push_back(temp);
        unordered_map<int,bool> mp;
        for(int i=idx;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()) continue;
            mp[nums[i]]=false;
            if(temp.size()==0 or temp[temp.size()-1]<=nums[i]){
                temp.push_back(nums[i]);
                f(nums,i+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        f(nums,0,temp);
        return result;
    }
};