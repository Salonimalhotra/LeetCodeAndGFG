#include<bits/stdc++.h>
#include<vector>
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        
        vector<int>next(n+1,0);
        vector<int>curr(n+1,0);
        // int **dp=new int *[n+1];
        // for(int i=0;i<=n;i++){
        //     dp[i]=new int[n+1];
        // }
        // for(int j=0;j<=n;j++){
        //     dp[n][j]=0;
        // }
        for(int index=n-1;index>=0;index--){
            for(int timer=index;timer>=0;timer--){
            // // we are starting timer from index coz we know that if we are at index 3 then we csnt have value of timer to be greater than 3;
            // for(int timer=n-1;timer>=0;timer--){ // this is also valid but there is no need for it coz we know at index 3 we can have maximum 4 as a timer but not more than that
                int incl=satisfaction[index] * (timer+1) + next[timer+1];
                int excl=next[timer];
                curr[timer]=max(incl,excl);
            }
            next=curr;
        }
        
        return next[0];
        
       
    }
};