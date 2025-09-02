class Solution {
public:
    int lowerbound(vector<int> &nums,int value){
        int hi=nums.size()-1;
        int low=0;
        while(low<=hi){
            int mid=low+(hi-low)/2;
            if(nums[mid]>=value){
                hi=mid-1;
            }
            else low=mid+1;
        }

        return low;
    }

    int upperbound(vector<int> &nums,int value){
        int hi=nums.size()-1;
        int low=0;
        while(low<=hi){
            int mid=low+(hi-low)/2;
            if(nums[mid]>value){
                hi=mid-1;
            }
            else low=mid+1;
        }

        return low;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=lowerbound(nums,target);
        int hi=upperbound(nums,target);
        if(low>=nums.size() or nums[low]!=target) return {-1,-1};
        return {low,hi-1};
    }
};