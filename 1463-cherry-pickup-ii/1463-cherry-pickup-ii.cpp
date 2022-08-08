#include<vector>
#include<bits/stdc++.h>
class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j1,int j2,  int ***dp){
        if(j1>=grid[0].size() || j2>=grid[0].size() || j1<0 || j2<0 || i<0 || i>=grid.size()){
            return -1e9;
        }
        
        if(i==grid.size()-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else if(j1!=j2){
                return grid[i][j1] + grid[i][j2];
            }
        }
         
       if(dp[i][j1][j2]!=-1){
           return dp[i][j1][j2];
       }
        int maxi=0;
        int dir[3]={-1,0,1};
        for(int dj1=0;dj1<=2;dj1++){
            for(int dj2=0;dj2<=2;dj2++){
                if(j1==j2){
                    maxi=max(maxi,grid[i][j1] + solve(grid,i+1,j1+dir[dj1],j2+dir[dj2],dp));
                    
                }
                
                else{
                    maxi=max(maxi, grid[i][j1] + grid[i][j2] + solve(grid,i+1,j1+dir[dj1],j2+dir[dj2],dp));
                }
            }
        }
        
        return dp[i][j1][j2]=maxi;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int ***dp=new int **[rows];
        for(int i=0;i<rows;i++){
            dp[i]=new int *[cols];
            for(int j=0;j<cols;j++){
                dp[i][j]=new int[cols];
                for(int k=0;k<cols;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        return solve(grid,0,0,cols-1,dp);
        
    }
};