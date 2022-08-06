#include<iostream>
#include<vector>
class Solution {
public:
    int helper(vector<int>&slices,int index,int turnsLeft,int **dp){
        if(index>=slices.size() || turnsLeft==0){
            return 0;
        }
        if(dp[index][turnsLeft]!=-1){
            return dp[index][turnsLeft];
        }
        int option1=slices[index] + helper(slices,index+2,turnsLeft-1,dp);
        int option2=helper(slices,index+1,turnsLeft,dp);
        return dp[index][turnsLeft]=max(option1,option2);
    }
    int solve(vector<int>& slices,int turns){
        int n=slices.size();
        int **dp=new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new int[turns+1];
            for(int j=0;j<=turns;j++)     {
                dp[i][j]=-1;
            }                
        }
       return helper(slices,0,turns,dp);
    }
    int maxSizeSlices(vector<int>& slices) {
        int turns=slices.size()/3;
        vector<int>x1;
        vector<int>x2;
        for(int i=0;i<slices.size();i++){
            if(i==0){
                x1.push_back(slices[i]);
            }
            else if(i==slices.size()-1){
                x2.push_back(slices[i]);
            }
            else{
                x1.push_back(slices[i]);
                x2.push_back(slices[i]);
            }
        }
        return max(solve(x1,turns),solve(x2,turns));        
    }
};