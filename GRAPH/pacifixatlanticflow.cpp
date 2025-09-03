class Solution {
public:
    int maxrow;
    int maxcol;
    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic;
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(vector<vector<int>> &heights,int row,int col,vector<vector<bool>> &visit){
        visit[row][col]=true;
        for(auto i:dir){
            int newrow=row+i[0];
            int newcol=col+i[1];
            if(newrow<0 or newcol<0 or newcol>=maxcol or newrow>=maxrow) continue;
            if(heights[row][col]>heights[newrow][newcol]) continue;
            if(visit[newrow][newcol]) continue;
            dfs(heights,newrow,newcol,visit);
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        maxrow=heights.size();
        maxcol=heights[0].size();
        pacific.assign(maxrow,vector<bool> (maxcol,false));
        atlantic.assign(maxrow,vector<bool> (maxcol,false));

        for(int i=0;i<maxrow;i++){
            dfs(heights,i,0,pacific);
            dfs(heights,i,maxcol-1,atlantic);
        }

        for(int i=0;i<maxcol;i++){
            dfs(heights,0,i,pacific);
            dfs(heights,maxrow-1,i,atlantic);
        }

        vector<vector<int>> res;
        for(int i=0;i<maxrow;i++){
            for(int j=0;j<maxcol;j++){
                if(pacific[i][j] and atlantic[i][j]) res.push_back({i,j});
            }
        }

        return res;

    }
};