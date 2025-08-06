class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> st;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            st.insert(curr);
            for(auto i:rooms[curr]){
                if(st.count(i)==0){
                    q.push(i);
                }
            }
        }

        return rooms.size()==st.size();
    }
};