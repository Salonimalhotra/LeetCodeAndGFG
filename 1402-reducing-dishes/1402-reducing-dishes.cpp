#include<bits/stdc++.h>
class Solution {
public:
    int solve(vector<int>& satisfaction,int index,int timer,int n,vector<vector<int>>&dp){
        if(index==n){
            return 0;
        }
        if(dp[index][timer]!=-1){
            return dp[index][timer];
        }
        int incl=satisfaction[index] * timer+ solve(satisfaction,index+1,timer+1,n,dp);
        int excl=solve(satisfaction,index+1,timer,n,dp);
        return dp[index][timer]=max(incl,excl);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();     
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solve(satisfaction,0,1,n,dp);
        
        if(ans<0){
            return 0;
        }
        else{
            return ans;
        }
        
    }
};