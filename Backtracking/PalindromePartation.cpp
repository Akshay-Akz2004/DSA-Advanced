class Solution {
public:
    vector<vector<string>> result;
    bool ispalindrome(const string &s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    void f(string &s,int idx,vector<string> &temp){
        
        if(idx==s.size()){
            result.push_back(temp);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(ispalindrome(s.substr(idx,i-idx+1))){
                temp.push_back(s.substr(idx,i-idx+1));
                f(s,i+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        f(s,0,temp);
        return result;
    }
};