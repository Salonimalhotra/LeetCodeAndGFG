#include<vector>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int suffixMax[prices.size()];
        suffixMax[n-1]=prices[n-1];
        for(int j=n-2;j>=0;j--){
            suffixMax[j]=max(suffixMax[j+1],prices[j]);
        }
        
        int max_profit=0;
        for(int i=0;i<prices.size();i++){
            int profit=suffixMax[i]-prices[i];
            max_profit=max(max_profit,profit);
        }
        return max_profit;
        
    }
};