class Solution {
  public:
    int findCatalan(int n) {
        if(n==0 or n==1) return 1;
        if(n==2) return 2;
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=findCatalan(i-1)*findCatalan(n-i);
        }
        
        return sum;
    }
};