class Solution {
public:
    vector<vector<int>> result;
    void f(int k,int target,vector<int> &temp,int idx){
        if(k==0 and target==0){
            result.push_back(temp);
            return;
        }
        if(target==0 or k==0) return;
        for(int i=idx;i<=9;i++){
            temp.push_back(i);
            f(k-1,target-i,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        f(k,n,temp,1);
        return result;
    }
};