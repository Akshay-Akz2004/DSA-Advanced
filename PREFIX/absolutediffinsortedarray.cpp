class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        vector<int> pre(n+1,0);
        vector<int> suf(n+1,0);
        pre[0]=0;
        for(int i=1;i<n;i++){
            if(security[i]<=security[i-1]){
                pre[i]=pre[i-1]+1;
            }
            else {
                pre[i]=0;
            }
        
        }

        suf[n-1]=0;
        for(int i=n-2;i>=0;i--){
            if(security[i]<=security[i+1]){
                suf[i]=suf[i+1]+1;
            }

            else {
                suf[i]=0;
            }
        }


        vector<int> res;
        for(int i=time;i<n-time;i++){
            if(pre[i]>=time and suf[i]>=time) res.push_back(i);
        }

        return res;


    }
};