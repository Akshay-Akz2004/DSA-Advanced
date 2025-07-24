class Solution {
public:
    int maxr;
    int maxc;
    vector<int> x={0,0,-1,1};
    vector<int> y={-1,1,0,0};
    bool f(vector<vector<char>> &board,string &word,int row,int col,int idx){
        if(idx==word.size()) return true;
        if(row>=maxr or row<0 or col>=maxc or col<0 ) return false;
        if(board[row][col]!=word[idx]) return false;
        char temp=board[row][col];
        board[row][col]='.';
        bool flag;
        for(int i=0;i<4;i++){
            
            flag=f(board,word,row+x[i],col+y[i],idx+1);
            if(flag) break;
        }
        board[row][col]=temp;
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        maxr=row;
        maxc=col;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]!=word[0]) continue;
                bool flag=f(board,word,i,j,0);
                if(flag) return true;
            }
        }

        return false;
    }
};