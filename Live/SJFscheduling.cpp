// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        int n=bt.size();
        vector<int> wt(n);
        wt[0]=0;
        for(int i=1;i<n;i++){
            wt[i]=wt[i-1]+bt[i-1];
        }
        
        long long sum=0;
        for(auto i:wt) sum+=i;
        return sum/(long long)n;
    }
};