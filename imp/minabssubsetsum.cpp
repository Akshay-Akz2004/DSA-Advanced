class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        int s=0;
        for(auto i:arr) s+=i;
        vector<vector<int>> dp;
        dp.assign(n,vector<int> (s+1,0));
        
        for(int i=0;i<n;i++) dp[i][0]=1;
        
        if(arr[0]<=s) dp[0][arr[0]]=1;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=s;j++){
                int take=false;
                if(j-arr[i]>=0) take=dp[i-1][j-arr[i]]; 
                int nottake=dp[i-1][j];
                dp[i][j]=take or nottake;
            }
            
        }
        int mindiff=INT_MAX;
        for(int i=0;i<=s;i++){
            if(dp[n-1][i]==1){
                int val1=i;
                int val2=s-i;
                mindiff=min(mindiff,abs(val1-val2));
            }
        }
        
        return mindiff;
        
    }
};
