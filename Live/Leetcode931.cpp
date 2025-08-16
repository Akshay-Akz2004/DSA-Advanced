class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<vector<int>> &matrix,int row,int col){
        if(row==matrix.size()-1) return matrix[row][col];

        if(dp[row][col]!=INT_MAX) return dp[row][col];
        if(col==0 and col!=matrix.size()-1){
            int case2=f(matrix,row+1,col);
            int case3=f(matrix,row+1,col+1);
            return dp[row][col]=matrix[row][col]+min(case2,case3);
        }

        else if(col==matrix.size()-1 and col!=0){
            int case1=f(matrix,row+1,col-1);
            int case2=f(matrix,row+1,col);
            return dp[row][col]= matrix[row][col]+min(case1,case2);
        }

        else{
            int case1=f(matrix,row+1,col-1);
        int case2=f(matrix,row+1,col);
        int case3=f(matrix,row+1,col+1);
        return dp[row][col]=matrix[row][col]+min({case1,case2,case3});
        }


    }
    int minFallingPathSum(vector<vector<int>>& matrix) {

        if(matrix[0].size()==1){

            int sum=0;
            for(auto i:matrix) sum+=i[0];
            return sum;
        }
        int row=matrix.size();
        dp.assign(row+1,vector<int> (row+1,INT_MAX));
        int minval=INT_MAX;
        for(auto i=0;i<matrix.size();i++){
            minval=min(minval,f(matrix,0,i));
        }

        return minval;
    }
};