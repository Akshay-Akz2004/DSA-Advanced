class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        long long sum=0;
        for(int i:beans) sum+=i;
        long long minval=LLONG_MAX;
        int n=beans.size();
        for(int i=0;i<n;i++){
            long long area=1LL* beans[i]*(n-i);
            minval=min(minval,sum-area);
        }

        return minval;
    }
};