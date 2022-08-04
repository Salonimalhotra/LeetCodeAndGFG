#include<climits>
#include<bits/stdc++.h>
class Solution {
public:    
    int numSquaresHelper(int n,int *dp) {
        if(n<0){
            return INT_MAX;
        }
        
        else if(dp[n]!=-1){
            return dp[n];
        }
        else if(n==0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        else if(n==2){
            return 2;
        }
        else if(n==3){
            return 3;
        }
        
        int minAns=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int smallAns=numSquaresHelper(n-i*i,dp);
            if(smallAns!=INT_MAX){
                if(smallAns+1<=minAns){
                    minAns=smallAns+1;
                }
            }
        }
        dp[n]=minAns;
        return dp[n];
    }
    
    
    int numSquares(int n){
        int *dp=new int[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=-1;
        }
        
        return numSquaresHelper(n,dp);
    }
};