class Solution {
  public:
  
    bool isvalid(int val,vector<int> &arr,int k){
        int count=0;
        int sum=0;
        for(auto i:arr){
            if(sum+i>val){
                sum=i;
                count+=1;
            }
            else sum=sum+i;
        }
        
        if(sum!=0) count++;
        return count<=k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k>arr.size()) return -1;
        int low=*max_element(arr.begin(),arr.end());
        int high=0;
        for(auto i:arr) high+=i;
        int valid=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isvalid(mid,arr,k)){
                high=mid-1;
                valid=mid;
            }
            else{
                low=mid+1;
            }
        }
        
        return valid;
    }
};