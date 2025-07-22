//Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:

//Subtract 1 from it. (n = n - ­1)
//If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2)
//If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3)

#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
int f(int n){
    if(n==1) return 0;
    if(dp[n]!=-1) return dp[n];
    int c1=f(n-1);
    int c2=(n%2==0?f(n/2):INT_MAX);
    int c3=(n%3==0?f(n/3):INT_MAX);
    return dp[n]=1+min({c1,c2,c3});
}
int main(){
    int n;
    cin>>n;
    dp.assign(n+1,-1);
    cout<<f(n);
}