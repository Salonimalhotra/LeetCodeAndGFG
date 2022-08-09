#include<bits/stdc++.h>
#include<string>
class Solution {
public:
//     bool solve(string s,string p,int n,int m,vector<vector<int>>&dp){       
//        if(n==0 && m==0){
//            return true;
//        }
        
//        else if(n!=0 && m==0){
//            return false;
//        } 
//        else if(n==0 && m!=0){
//            for(int i=0;i<m;i++){
//                if(p[i]!='*'){
//                    return false;
//                }
//            }
//            return true;
//        }
        
//        if(dp[n][m]!=-1){
//            return dp[n][m];
//        }
//        if(s[n-1]==p[m-1] || p[m-1]=='?'){
//           return dp[n][m]=solve(s,p,n-1,m-1,dp);
//        }
        
//        if(p[m-1]=='*'){
//            bool option1=solve(s,p,n-1,m,dp);
//            bool option2=solve(s,p,n,m-1,dp);
//            return dp[n][m]=option1 || option2;
//        } 
       
//        else{
//            return dp[n][m]=false;
//        }        
//     }
    
    bool Tab(string s,string p){
              int n=s.size();
              int m=p.size();
             vector<vector<int>>dp(n+1,vector<int>(m+1,0));
             dp[0][0]=1;
        
             for(int i=1;i<=n;i++){
                 dp[i][0]=0;
             }
        
            for(int j=1;j<=m;j++){
                int flag=1;
                for(int i=0;i<j;i++){
                 if(p[i]!='*'){
                   flag=0;
                    break;
                  }                    
                 }
                 dp[0][j]=flag;             
            }
        
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(s[i-1]==p[j-1] || p[j-1]=='?'){
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else if(p[j-1]=='*'){
                        dp[i][j]=dp[i-1][j] || dp[i][j-1];
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
            }
        return dp[n][m];
    }
    
    bool isMatch(string s, string p) {
              // int n=s.size();
              // int m=p.size();
              // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
              return Tab(s,p);
    }
};