class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        //as size of obstacles is n+1 therefore or last target pos will be size-1
        //therefore n will also be size-1
        int n=obstacles.size()-1;
        
        vector<int>next(4,INT_MAX-1);
        vector<int>curr(4,INT_MAX-1);
        
        next[0]=0;
        next[1]=0;
        next[2]=0;
        next[3]=0;
        
        // for the last position we have already filled the next vector
        //hence we will be starting from the current vector
        for(int currpos=n-1;currpos>=0;currpos--){
            
            for(int currentlane=1;currentlane<=3;currentlane++){
                
                if(obstacles[currpos+1]!=currentlane){
                    curr[currentlane]=next[currentlane];
                }
                else{
                    //we take a sidejump;
                    int ans=INT_MAX-1;
                    for(int i=1;i<=3;i++){
                        if(obstacles[currpos]!=i && currentlane!=i){
                            ans=min(ans,1+next[i]);
                        }
                    }
                    curr[currentlane]=ans;
                }
            }
            next=curr;
         }
        
        return min(next[2], min(1+next[1],1+next[3]));       
        
    }
};