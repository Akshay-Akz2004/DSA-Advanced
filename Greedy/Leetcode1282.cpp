class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        vector<vector<int>> result;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
            if(mp[nums[i]].size()==nums[i]){
                result.push_back(mp[nums[i]]);
                mp.erase(nums[i]);
            }
        }

        for(auto i:mp){
            result.push_back(i.second);
        }

        return result;
    }
};