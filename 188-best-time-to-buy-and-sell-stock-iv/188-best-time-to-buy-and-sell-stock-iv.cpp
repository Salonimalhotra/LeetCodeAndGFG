class Solution {
public:
    int tab(vector<int>& prices,int k){
         int n=prices.size();
         // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
          vector<vector<int>>ahead(2,vector<int>(k+1,0));
          vector<vector<int>>curr(2,vector<int>(k+1,0));
        
        
         for(int index=n-1;index>=0;index--){
             for(int previousBuy=0;previousBuy<=1;previousBuy++){
                 for(int cap=1;cap<=k;cap++){
                     int option1;
                     int option2;
                     if(previousBuy){
                  // if previousbuy is 1 , it means that cannot buy here , we have to sell here
                option1=prices[index] + ahead[0][cap-1];
                option2=ahead[1][cap];
            
                    }
        
                  else{ 
                 // buy 
                  option1=-1 * prices[index] + ahead[1][cap];
                 option2 =ahead[0][cap];
              
                  }
             curr[previousBuy][cap]=max(option1,option2); 
                     
                 }
             }
             ahead=curr;
         }
        return ahead[0][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        return tab(prices,k);
    }
};