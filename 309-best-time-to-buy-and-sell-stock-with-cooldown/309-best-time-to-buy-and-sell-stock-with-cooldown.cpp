#include<vector>
#include<bits/stdc++.h>
class Solution {
public:
    int solve(vector<int>&prices,int index,int prevBuy,vector<vector<int>>&dp){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][prevBuy]!=-1){
            return dp[index][prevBuy];
        }
        int option1;
        int option2;
        if(prevBuy==1){
            // we have previously bought now we can only sell
            option1=prices[index] + solve(prices,index+2,0,dp);
            option2=solve(prices,index+1,1,dp);
        }
        
        else{
            option1=-1 * prices[index] + solve(prices,index+1,1,dp);
            option2=solve(prices,index+1,0,dp);
        }
        
        return dp[index][prevBuy]=max(option1,option2);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+2,vector<int>(2,-1));
        return solve(prices,0,0,dp);
    }
};