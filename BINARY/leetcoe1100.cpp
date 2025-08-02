// capacity to ship withing D days
class Solution {
public:
    bool isValid(int cap,vector<int> &weights,int days){
        int count=0;
        int temp=0;
        for(auto i:weights){
            if(temp+i>cap){
                count+=1;
                temp=i;
            }
            else temp+=i;
        }

        if(temp!=0) count+=1;
        return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(auto i:weights) high+=i;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(mid,weights,days)){
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