class Solution {
  public:
    bool isValid(int mid,vector<int> &arr,int k){
        int sum=0;
        int limit=0;
        for(auto i:arr){
            if(i>mid) return false;
            if(sum+i>mid){
                sum=i;
                limit++;
            }
            else sum+=i;
        }
        
        if(sum!=0) limit++;
        return limit<=k;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int low=*min_element(arr.begin(),arr.end());
        int high=0;
        for(auto i:arr) high+=i;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(mid,arr,k)){
                high=mid-1;
                ans=mid;
            }
            
            else low=mid+1;
        }
        
        return ans;
    }
};