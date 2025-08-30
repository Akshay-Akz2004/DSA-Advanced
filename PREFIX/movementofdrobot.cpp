class Solution {
public:
    #define MOD 1000000007
    int sumDistance(vector<int>& nums, string s, int d) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(s[i]=='R') nums[i]+=d;
            else nums[i]-=d;
        }

        sort(nums.rbegin(),nums.rend());
        vector<long long> suf(n);
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=(suf[i+1]%MOD+ (long long)nums[i]%MOD)%MOD;
        }

        long long sum=0;
        for(int i=0;i<n-1;i++){
            int range=n-i-1;
            sum=(sum%MOD+(nums[i]*1LL*range)%MOD-suf[i+1]%MOD)%MOD;
        }

        return (int)sum;
    }
};