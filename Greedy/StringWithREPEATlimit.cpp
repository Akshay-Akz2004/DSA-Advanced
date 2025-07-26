class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        unordered_map<char,int> mp;
        for(auto i:s) mp[i]++;
        priority_queue<pair<char,int>> pq;
        for(auto i:mp) pq.push({i.first,i.second});
        string result="";
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            if(p.second<=limit){
                for(int i=0;i<p.second;i++) result+=p.first;
                continue;
            }

            else{
                for(int i=0;i<limit;i++) result+=p.first;
                p.second=p.second-limit;
                if(pq.empty()) break;
                pair<int,int> p2=pq.top();
                pq.pop();
                result+=p2.first;
                p2.second=p2.second-1;
                if(p2.second!=0){
                    pq.push(p2);
                }

                pq.push(p);
            }
        }

        return result;
    }
};