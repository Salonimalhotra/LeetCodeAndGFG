#include<vector>
#include<bits/stdc++.h>
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int mod=pow(10,9) + 7;
        int n=obstacleGrid[0].size();
         long long  ** dp=new long long  *[m];
        for(int i=0;i<m;i++){
            dp[i]=new long long int[n];
        }
        
        if(obstacleGrid[m-1][n-1]!=1)dp[m-1][n-1]=1;
        else{
            dp[m-1][n-1]=0;
        }
        for(int j=n-2;j>=0;j--){
            if(obstacleGrid[m-1][j]!=1)
            dp[m-1][j]=dp[m-1][j+1];
            else{
                dp[m-1][j]=0;
            }
        }
        
        for(int i=m-2;i>=0;i--){
            if(obstacleGrid[i][n-1]!=1)
            dp[i][n-1]=dp[i+1][n-1];
            else{
                dp[i][n-1]=0;
            }
        }
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(obstacleGrid[i][j]!=1){
                dp[i][j]=(dp[i+1][j] + dp[i][j+1]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        
        return dp[0][0];
    }
};