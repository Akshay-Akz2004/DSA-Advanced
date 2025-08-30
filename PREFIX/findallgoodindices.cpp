class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        prefix[0]=1;
        suffix[n-1]=1;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                prefix[i]=prefix[i-1]+1;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                suffix[i]=suffix[i+1]+1;
            }
        }

        vector<int> res;
        for(int i=k;i<n-k;i++){
            if(prefix[i-1]>=k and suffix[i+1]>=k) res.push_back(i);
        }

        return res;
    }
};