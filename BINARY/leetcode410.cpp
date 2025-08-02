class Solution {
public:
    bool isvalid(int mid,vector<int> &nums,int k){
        int sum=0;
        int count=0;
        for(auto i:nums){
            if(i+sum>mid){
                count+=1;
                sum=i;
            }
            else sum+=i;
        }

        if(sum!=0) count++;
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(auto i:nums) high+=i;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isvalid(mid,nums,k)){
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