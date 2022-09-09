class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int i=0;
        int minAns=0;
        
        if(rungs.size()==0){
            return 0;
        }
        if(rungs[0]-0>dist){
            int x=rungs[0]-0-1;
            minAns+=x/dist;
        }
        while(i+1<rungs.size()){
           if(rungs[i+1]-rungs[i]<=dist){
               i+=1;
           }
            else{
                int x=rungs[i+1]-rungs[i]-1;
                minAns+=x/dist;
                i=i+1;
            }
        }
        return minAns;
    }
};