class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int count=0;
        unordered_map<int,int> mp;
        for(auto i:answers){
            if(mp.find(i)==mp.end()){
                mp[i]=0;
            }
            else mp[i]++;
            if(mp[i]==i){
                count+=i+1;
                mp.erase(i);
            }
        }

        for(auto i:mp){
            count+=i.first+1;
        }

        return count;


    }
};