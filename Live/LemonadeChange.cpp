class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        int n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==10){
                if(mp[5]==0) return false;
                mp[5]--;
                mp[10]++;
            }

            else if(bills[i]==20){
                if(mp[5]!=0 and mp[10]!=0){
                    mp[5]--;
                    mp[10]--;
                    mp[20]++;
                }

                else if(mp[5]>=3){
                    mp[5]-=3;
                    mp[20]++;
                }

                else return false;


            }

            else mp[5]++;
        }

        return true;
    }
};