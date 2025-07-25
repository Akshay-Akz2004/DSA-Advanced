#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        while(k--){
            sort(nums.begin(),nums.end());
            nums[0]=-1*nums[0];
        }
        int ans=0;
        for(auto i:nums) ans+=i;
        return ans;
    }
};