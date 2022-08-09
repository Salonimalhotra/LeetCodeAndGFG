#include<vector>
#include<bits/stdc++.h>
class Solution {
public:
//     int solve(vector<int>&prices,int index,int previousBuy,vector<vector<int>>&dp){
//         if(index==prices.size()){
//             return 0;
//         }
//         if( dp[index][previousBuy]!=-1){
//             return dp[index][previousBuy];
//         }
        
//          int option1;
//          int option2;
//         if(previousBuy==true){
//             // if the item was previously bought then you can either sell at this index or can not sell at this index
//             option1=prices[index] + solve(prices,index,0,dp);
//             option2=solve(prices,index+1,1,dp);
//         }
        
//         else{
//             // if any item is not previously bought you here buy the item or not buy it  
//             option1= -1 * prices[index]  + solve(prices,index+1,1,dp);
//             option2= 0 + solve(prices,index+1,0,dp);
//         }
        
//         return dp[index][previousBuy]=max(option1,option2);
//     }
    
    int tab(vector<int>&prices){
          int n=prices.size();
         vector<vector<int>>dp(n+1,vector<int>(2,0));      
        
         for(int i=n-1;i>=0;i--){
             for(int j=0;j<=1;j++){
                 int option1;
                 int option2;
                 if(j==1){
                     option1=prices[i] + dp[i+1][0];
                     option2=dp[i+1][1];
                 }
                 else if(j==0){
                     option1=-1 * prices[i] + dp[i+1][1];
                     option2 = dp[i+1][0];
                 }
                 dp[i][j]=max(option1,option2);
             }
         }
        return dp[0][0];
    }
    int maxProfit(vector<int>& prices) {
        // int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return tab(prices);
       // return solve(prices,0,0,dp);   
    }
};