#include<string>
class Solution {
public:
    // int solve(string s,string t,int n,int m,vector<vector<int>>&dp){
    //     if(m==0){
    //         return 1;
    //     }
    //     if(n==0){
    //         return 0;
    //     }
    //     if(dp[n][m]!=-1){
    //         return dp[n][m];
    //     }
    //     if(s[n-1]==t[m-1]){
    //         int option1=solve(s,t,n-1,m,dp);
    //         int option2=solve(s,t,n-1,m-1,dp);
    //         return dp[n][m]= option1 + option2;
    //     }
    //     else{
    //         return dp[n][m]=solve(s,t,n-1,m,dp);
    //     }
    // }
    
    int tab(string s,string t){
         int n=s.size();
         int m=t.size();
        vector<double>prev(m+1,0);
        // vector<double>curr(m+1,0);
        prev[0]=1;
        // curr[0]=1;
        
        //  for(int i=0;i<=n;i++){
        //      dp[i][0]=1;
        //  }
        // for(int j=0;j<=m;j++){
        //     dp[0][j]=0;
        // }
        
        // dp[0][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]){
                    prev[j]=prev[j] + prev[j-1];
                }
                // else{
                //     curr[j]=prev[j];
                // }
            }
             // prev=curr;
        }
        
        return (int)prev[m];
        
    }
    int numDistinct(string s, string t) {
        // int n=s.size();
        // int m=t.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return solve(s,t,s.size(),t.size(),dp);
        return tab(s,t);
    }
};