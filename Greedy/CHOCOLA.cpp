// User function Template for C++

bool cmp(int a,int b){
    return a>b;
}

class Solution {
  public:
    int minimumCostOfBreaking(vector<int> x, vector<int> y, int M, int N) {
        // Write your code here
        int xi=0;
        int yi=0;
        int hpiece=1;
        int vpiece=1;
        int total=0;
        sort(x.begin(),x.end(),cmp);
        sort(y.begin(),y.end(),cmp);
        while(xi<x.size() and yi<y.size()){
            if(x[xi]>y[yi]){
                total+=x[xi]*vpiece;
                hpiece++;
                xi++;
            }
            
            else{
                total+=y[yi]*hpiece;
                vpiece++;
                yi++;
            }
        }
        
        while(xi<x.size()){
             total+=x[xi]*vpiece;
             xi++;
        }
        
        while(yi<y.size()){
             total+=y[yi]*hpiece;
             yi++;
        }
        
        return total;
    }
};
