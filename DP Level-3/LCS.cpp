#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    int f(string &text1,string &text2,int idx1,int idx2){
        if(idx1==text1.size() or idx2==text2.size()) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(text1[idx1]==text2[idx2]) return dp[idx1][idx2]= 1+f(text1,text2,idx1+1,idx2+1);
        int first=f(text1,text2,idx1+1,idx2);
        int second=f(text1,text2,idx1,idx2+1);
        return dp[idx1][idx2]= max(first,second);
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(text1.size()+1,vector<int> (text2.size()+1,-1));
        return f(text1,text2,0,0);
    }
};