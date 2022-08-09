#include<bits/stdc++.h>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // first Approach - O{n^2} - time complexity
//         int maxProfit=0;
//         for(int i=0;i<prices.size();i++){
//             int mini=INT_MAX;
//             for(int j=i-1;j>=0;j--){
//                 mini=min(prices[j],mini);
//             }
//             maxProfit=max(maxProfit,prices[i]-mini);
//         }
        
//         return maxProfit;
        
        // second Approach - O{n} -time complexity and O{n}- space complexity
//         int minArray[prices.size()];
//         minArray[0]=prices[0];
//         int profit=0;
//         for(int j=1;j<prices.size();j++){
//             minArray[j]=min(minArray[j-1],prices[j]);
//         }
        
//         for(int i=1;i<prices.size();i++){
//             profit=max(profit,prices[i]-minArray[i]);
//         }
//         return profit;
        
        // third Approach - O(n)time  and O{1} - space
        int profit=0;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++){
            int cost=prices[i]- mini;
            profit=max(profit,cost);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};