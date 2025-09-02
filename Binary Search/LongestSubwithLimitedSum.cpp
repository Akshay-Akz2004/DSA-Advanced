class Solution {
public:
    int lower(vector<int> &nums,int val){
        int low=0;
        int hi=nums.size()-1;
        while(low<=hi){
            int mid=low+(hi-low)/2;
            if(nums[mid]>val) hi=mid-1;
            else low=mid+1;
        }

        return low;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]=nums[i-1]+nums[i];
        }
        vector<int> result;
        for(auto i:queries){
            int x=lower(nums,i);
            result.push_back(x);
        }

        return result;

    }
};