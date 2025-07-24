class Solution {
public:
    unordered_map<int, int> mp;
    vector<int> dp;

    int f(vector<int>& nums, int idx) {
        if (idx >= nums.size()) return 0;
        if (dp[idx] != -1) return dp[idx];

        int earn = nums[idx] * mp[nums[idx]];
        int skip = f(nums, idx + 1);

        int take;
        if (idx + 1 < nums.size() && nums[idx + 1] == nums[idx] + 1)
            take = earn + f(nums, idx + 2);
        else
            take = earn + f(nums, idx + 1);

        return dp[idx] = max(skip, take);
    }

    int deleteAndEarn(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums) {
            mp[num]++;
            st.insert(num);
        }

        nums.clear();
        for (int num : st) nums.push_back(num);

        sort(nums.begin(), nums.end()); 

        dp.assign(nums.size(), -1);
        return f(nums, 0);
    }
};
