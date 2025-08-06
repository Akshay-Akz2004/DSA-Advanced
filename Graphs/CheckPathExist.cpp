class Solution {
public:
    bool validPath(int n, vector<vector<int>>& e, int source, int destination) {
        unordered_map<int,vector<int>> graph;
        for(auto i:e){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }

        queue<int> qu;
        qu.push(source);
        unordered_set<int> st;
        st.insert(source);
        while(!qu.empty()){
            int curr=qu.front();
            if(curr==destination) return true;
            qu.pop();
            for(auto i:graph[curr]){
                if(st.count(i)==0){
                    qu.push(i);
                    st.insert(i);
                }
            }
        }

        return false;

    }
};