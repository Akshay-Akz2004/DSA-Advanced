#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,c,k;
    while(cin>>n>>c>>k){
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> cnt(c+1,0);
            for(int j=i;j<n;j++){
                cnt[a[j]]++;
                bool ok=true;
                for(int x=1;x<=c;x++){
                    if(cnt[x]>0 && cnt[x]<k){
                        ok=false;
                        break;
                    }
                }
                if(ok){
                    ans=max(ans,j-i+1);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}