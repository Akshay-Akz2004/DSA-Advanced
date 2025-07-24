class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum=INT_MIN;
        int minsum=INT_MAX;
        int sum=0;
        int nsum=0;
        int totalsum=0;
        for(auto i:nums){
            totalsum+=i;
            sum=sum+i;
            maxsum=max(sum,maxsum);
            if(sum<0) sum=0;
            nsum=nsum+i;
            minsum=min(nsum,minsum);
            if(nsum>0) nsum=0;
        }
        if(maxsum<0) return maxsum;
        return max(maxsum,totalsum-minsum);
    }
};