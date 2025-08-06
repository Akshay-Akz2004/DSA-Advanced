class Solution {
public:
    int maxrow;
    int maxcol;
    vector<int> x={0,1,-1,0};
    vector<int> y={1,0,0,-1};
    void f(vector<vector<int>> &image,int sr,int sc,int color,int target){
        if(sr<0 or sr>=maxrow or sc<0 or sc>=maxcol) return;
        if(image[sr][sc]!=target) return;
        image[sr][sc]=color;
        for(int i=0;i<4;i++){
            f(image,sr+x[i],sc+y[i],color,target);
        }

        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        maxrow=image.size();
        maxcol=image[0].size();
        int target=image[sr][sc];
        if(color==target) return image;
        f(image,sr,sc,color,target);
        return image;
    }
};