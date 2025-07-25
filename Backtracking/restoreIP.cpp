#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> result;
    bool isvalid(string &s){
        if(s[0]=='0' and s.size()>1) return false;
        long long digit=0;
        for(auto i:s){
            digit=digit*10+(i-'0');
            if(digit>255) return false;
        }
        return true;
    }
    void f(const string &s,vector<string> &temp){
        if(temp.size()==4 and s.size()==0){
            string k="";
            k+=temp[0];
            for(int i=1;i<4;i++){
                k+='.';
                k+=temp[i];
            }
            result.push_back(k);
            return;
        }
        for(int i=0;i<s.size();i++){
            string x=s.substr(0,i+1);
            if(isvalid(x) and temp.size()<4){
                temp.push_back(x);
                f(s.substr(i+1),temp);
                temp.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> temp;
        f(s,temp);
        return result;
        
    }
};