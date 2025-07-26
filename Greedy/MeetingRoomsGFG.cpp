class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        int i=0;
        int j=0;
        int maxreq=0;
        int room=0;
        while(i<start.size()){
            if(start[i]<end[j]){
                room++;
                i++;
            }
            
            else if(start[i]>end[j]){
                room--;
                j++;
            }
            else{
                i++;
                j++;
            }
            
            maxreq=max(room,maxreq);
        }
        
        return maxreq;
    }
};
