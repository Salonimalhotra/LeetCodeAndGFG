#include<iostream>
#include<vector>
#include<bits/stdc++.h>
class Solution {
public:
    int solve(vector<int>&prices,int index,int previousBuy,int cap,vector<vector<vector<int>>>&dp){
        if(index==prices.size() || cap==0){
            return 0;
        }
        if(dp[index][previousBuy][cap]!=-1){
            return dp[index][previousBuy][cap];
        }
        // two choices at every index;
        int option1;
        int option2;
        if(previousBuy){
            // if previousbuy is 1 , it means that cannot buy here , we have to sell here
            option1=prices[index] + solve(prices,index+1,0,cap-1,dp);
            option2=solve(prices,index+1,1,cap,dp);
            
        }
        
        else{
            // buy 
             option1=-1 * prices[index] + solve(prices,index+1,1,cap,dp);
             option2 = solve(prices,index+1,0,cap,dp);
              
        }
         return dp[index][previousBuy][cap]=max(option1,option2); 
    }
    int maxProfit(vector<int>& prices){
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,0,2,dp);
    }
};