#include<bits/stdc++.h>
using namespace std;

int dp[2005][2005][10];
int lcs(vector<int> &v1,vector<int> &v2,int idx1,int idx2,int k){
	if(idx1==v1.size() or idx2==v2.size()) return 0;
	if(dp[idx1][idx2][k]!=-1) return dp[idx1][idx2][k];
	if(v1[idx1]==v2[idx2]) return dp[idx1][idx2][k]=1+lcs(v1,v2,idx1+1,idx2+1,k);
	if(k>0){
		return dp[idx1][idx2][k]=max({
		1+lcs(v1,v2,idx1+1,idx2+1,k-1),
		lcs(v1,v2,idx1+1,idx2,k),
		lcs(v1,v2,idx1,idx2+1,k)
		});
	}

	return dp[idx1][idx2][k]=max(
			lcs(v1,v2,idx1+1,idx2,k),
			lcs(v1,v2,idx1,idx2+1,k)
	);
}

int main(){
	memset(dp,-1,sizeof(dp));
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> v1(m,0);
	vector<int> v2(n,0);
	for(int i=0;i<m;i++) cin>>v1[i];
	for(int i=0;i<n;i++) cin>>v2[i];
	cout<<lcs(v1,v2,0,0,k);
}