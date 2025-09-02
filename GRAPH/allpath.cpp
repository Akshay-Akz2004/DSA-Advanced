class Solution {
public:
    vector<vector<int>> res;
    unordered_set<int> visited;
    void dfs(vector<vector<int>> &graph,vector<int>&path,int start,int end){
        if(start==end){
            path.push_back(start);
            res.push_back(path);
            path.pop_back();
        }
        visited.insert(start);
        path.push_back(start);
        for(auto neighbour:graph[start]){
            if(not visited.count(neighbour)){
                dfs(graph,path,neighbour,end);
            }
        }

        path.pop_back();
        visited.erase(start);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int start=0;
        int end=graph.size()-1;
        vector<int> path;
        dfs(graph,path,start,end);
        return res;
    }
};