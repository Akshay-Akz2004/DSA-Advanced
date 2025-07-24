class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>&nums,int idx,vector<int>&result){
        if(idx==nums.size()){
            ans.push_back(result);
            return;
        }
        result.push_back(nums[idx]);
        f(nums,idx+1,result);
        result.pop_back();
        f(nums,idx+1,result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> result;
        f(nums,0,result);
        return ans;      
    }
};