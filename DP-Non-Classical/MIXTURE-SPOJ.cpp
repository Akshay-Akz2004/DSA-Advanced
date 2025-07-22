#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int color(int i,int j,vector<int> &arr){
    int col=0;
    for(int k=i;k<=j;k++){
        col=(col%100+arr[k]%100)%100;
    }
    return col;
}

int f(int i,int j,vector<int>&arr){
    if(i==j) return 0;
    if(i+1==j) return arr[i]*arr[j];
    if(dp[i][j]!=-1) return dp[i][j];
    int result=INT_MAX;
    for(int k=i;k<j;k++){
        result=min(result,f(i,k,arr)+f(k+1,j,arr)+color(i,k,arr)*color(k+1,j,arr));
    }

    return dp[i][j]=result;
}

int main(){
    
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        dp.clear();
        dp.assign(n+1,vector<int>(n+1,-1));
        vector<int> v(n,0);
        for(int i=0;i<n;i++) cin>>v[i];       
        cout<<f(0,n-1,v)<<endl;
    }
}