class Solution {
public:
    int count=0;
    int kr;
    void f(vector<int> &nums,int idx,unordered_map<int,int> &mp){
        if(idx==nums.size()){
            count+=1;
            return;
        }

        if(mp.find(nums[idx]-kr)==mp.end()){
            mp[nums[idx]]++;
            f(nums,idx+1,mp);
            mp[nums[idx]]--;
            if(mp[nums[idx]]==0) mp.erase(nums[idx]);
        }

        f(nums,idx+1,mp);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        kr=k;
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end());
        f(nums,0,mp);
        return count-1;
    }
};