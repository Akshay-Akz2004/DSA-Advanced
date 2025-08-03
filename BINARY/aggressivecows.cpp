class Solution {
  public:
    
    bool isValid(int mid,vector<int> &arr,int k){
        int count=1;
        int dist=arr[0];
        for(auto i=1;i<arr.size();i++){
            if(arr[i]-dist>=mid){
                count+=1;
                dist=arr[i];
            }
        }
        
        return count>=k;
    } 
    
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[stalls.size()-1]-stalls[0];
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(mid,stalls,k)){
                ans=mid;
                low=mid+1;
                
            }
            
            else high=mid-1;
        }
        
        return ans;
    }
};