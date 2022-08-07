#include<vector>
#include<bits/stdc++.h>
class Solution {
public:    
    int countSquares(vector<vector<int>>& matrix) {
      int n=matrix.size();
      int m=matrix[0].size();
       int **dp=new int *[n];
       for(int i=0;i<n;i++){
           dp[i]=new int[m];
       }
        
       int totalAns=0; 
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(matrix[i][j]==1){
                   dp[i][j]=1;
                   totalAns++;
               }
           }
           
       } 
       
       for(int i=0;i<n;i++){
           if(matrix[i][m-1]==1){
               dp[i][m-1]=1;
           }
           else{
               dp[i][m-1]=0;
           }
       } 
        
        for(int j=0;j<m;j++){
           if(matrix[n-1][j]==1){
               dp[n-1][j]=1;
           }
           else{
               dp[n-1][j]=0;
           }
       } 
        
        
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                int minAns=INT_MAX;
                if(matrix[i][j]==1){
                    
                minAns=min(dp[i][j+1],min(dp[i+1][j+1],dp[i+1][j]));
                if(minAns!=INT_MAX){
                    minAns+=1;
                  
                for(int k=2;k<=minAns;k++){
                    totalAns++;
                }
                dp[i][j]+=minAns-1;
               }
                }
                else{
                    dp[i][j]=0;
                }                
                    
                
                
            }
        }        
        // cout<<dp[1][0]<<endl;
        return totalAns;
    }
};