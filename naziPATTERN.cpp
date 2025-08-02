#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<2*n+1;i++){
        for(int j=0;j<2*n+1;j++){
            if(i==0){
                if(j==0){
                    cout<<"*";
                }
                else if(j>0 and j<n){
                    cout<<" ";
                }
                else cout<<"*";
            }
            else if(i>0 and i<n){
                if(j==0){
                    cout<<"*";
                }
                else if(j>0 and j<n){
                    cout<<" ";
                }
                else if(j==n) cout<<"*";
            }
            
            else if(i==n){
                cout<<"*";
            }
            
            else if(i>n and i<2*n){
                if(j>=0 and j<n) cout<<" ";
                else if(j==n) cout<<"*";
                else if(j>n and j<2*n) cout<<" ";
                else cout<<"*";
            }
            else{
                if(j>=0 and j<=n) cout<<"*";
                else if(j>n and j<2*n) cout<<" ";
                else cout<<"*";
            }
        }
        cout<<endl;
    }
}