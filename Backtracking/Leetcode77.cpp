class Solution {
public:
    vector<vector<int>> result;
    void f(int n,int k,int idx,vector<int> &temp){
        if(k==0){
            result.push_back(temp);
            return;
        }
        for(int i=idx;i<=n;i++){
            temp.push_back(i);
            f(n,k-1,i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        f(n,k,1,temp);
        return result;
    }
};