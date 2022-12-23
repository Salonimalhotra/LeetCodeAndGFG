#include <vector>
#include <bits/stdc++.h>

class Solution
{
    public:
       	//     int solve(vector<int>&prices,int index,int prevBuy,vector<vector<int>>&dp){
       	//         if(index>=prices.size()){
       	//             return 0;
       	//         }
       	//         if(dp[index][prevBuy]!=-1){
       	//             return dp[index][prevBuy];
       	//         }
       	//         int option1;
       	//         int option2;
       	//         if(prevBuy==1){
       	//            	// we have previously bought now we can only sell
       	//             option1=prices[index] + solve(prices,index+2,0,dp);
       	//             option2=solve(prices,index+1,1,dp);
       	//         }

       	//         else{
       	//             option1=-1 *prices[index] + solve(prices,index+1,1,dp);
       	//             option2=solve(prices,index+1,0,dp);
       	//         }

       	//         return dp[index][prevBuy]=max(option1,option2);
       	//     }

       	//     int tab(vector < int>prices){
       	//         int n=prices.size();
       	//          vector<vector < int>>dp(prices.size()+2,vector < int>(2,0));
       	//          for(int index=n-1;index>=0;index--){
       	//              for(int prevBuy=0;prevBuy<=1;prevBuy++){

       	//                   int option1;
       	//                  int option2;
       	//                 if(prevBuy==1){
       	//            	// we have previously bought now we can only sell
       	//                 option1=prices[index] + dp[index+2][0];
       	//                 option2=dp[index+1][1];
       	//              }

       	//             else{
       	//              option1=-1 *prices[index] + dp[index+1][1];
       	//              option2=dp[index+1][0];
       	//            }

       	//            dp[index][prevBuy]=max(option1,option2);

       	//              }
       	//          }
       	//         return dp[0][0];
       	//     
        int recursive(vector<int> &prices, int index, bool buy, vector<vector< int>> &dp)
        {
            if (index >= prices.size())
            {
                return 0;
            }
            if (dp[index][buy] != -1)
            {
                return dp[index][buy];
            }
            int option1;
            int option2;
            if (buy == true)
            {
                option1 = prices[index] + recursive(prices, index + 2, false,dp);
                option2 = recursive(prices, index + 1, buy,dp);
            }
            else
            {
                option1 = -1 *prices[index] + recursive(prices, index + 1, true,dp);
                option2 = recursive(prices, index + 1, false,dp);
            }
            return dp[index][buy]=max(option1, option2);
        }
    int maxProfit(vector<int> &prices)
    {
       	// vector<vector < int>>dp(prices.size()+2,vector < int>(2,-1));
       	// return solve(prices,0,0,dp);
       	// return tab(prices);
        vector<vector < int>> dp(prices.size() + 2, vector<int> (2, -1));
        return recursive(prices, 0, 0,dp);
    }
};