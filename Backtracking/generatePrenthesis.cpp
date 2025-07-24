class Solution {
public:
    vector<string> result;
    void f(string &s,int open,int close,int n){
        if(open==n and close==n){
            result.push_back(s);
            return;
        }
        if(open>n or close>open) return;
        s.push_back('(');
        f(s,open+1,close,n);
        s.pop_back();
        s.push_back(')');
        f(s,open,close+1,n);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string temp="";
        f(temp,0,0,n);
        return result;
    }
};