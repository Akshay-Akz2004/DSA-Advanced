class Solution {
public:
    bool isValid(int mid,vector<int> &nums,int m,int k){
        int adj=0;
        int flower=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                adj++;
                if(adj==k){
                    flower++;
                    adj=0;
                }
            }
            else adj=0;
        }

        return flower>=m;


    }
    int minDays(vector<int>& nums, int m, int k) {
        if((long long)nums.size()<(long long)m*k) return -1;
        int high=*max_element(nums.begin(),nums.end());
        int low=*min_element(nums.begin(),nums.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(mid,nums,m,k)){
                high=mid-1;
                ans=mid;
            }

            else{
                low=mid+1;
            }
        }

        return ans;
    }
};