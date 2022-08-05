#include<bits/stdc++.h>
class Solution {
public:
    int solve(vector<int>& obstacles,int currpos,int currlane,int **dp){
        int n=obstacles.size();
        if(currpos==n-1){
            return 0;
        }
        
        if(dp[currpos][currlane]!=-1){
            return dp[currpos][currlane];
        }
        // we will move on to the next position in our current lane if there is not obstacles at the next position 
        if(obstacles[currpos+1]!=currlane){
            dp[currpos][currlane]=solve(obstacles,currpos+1,currlane,dp);
            return dp[currpos][currlane];
        }
        
        int minAns=INT_MAX;
        for(int i=1;i<=3;i++){
            if(currlane!=i && obstacles[currpos]!=i){
                minAns=min(minAns,1+solve(obstacles,currpos,i,dp));
            }
        }
        return dp[currpos][currlane]=minAns;
    }
    int minSideJumps(vector<int>& obstacles) {
        int currpos=0;
        int currlane=2;
        int n=obstacles.size()-1;
        int **dp=new int *[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new int[4];
            for(int j=0;j<=3;j++){
                dp[i][j]=-1;
            }
        }
        return solve(obstacles,currpos,currlane,dp);
        
    }
};