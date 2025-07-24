class Solution {
public:
    vector<vector<int>> result;
    void f(vector<int> &nums,int idx){
        if(nums.size()==idx){
            result.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            f(nums,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        f(nums,0);
        return result;
    }
};