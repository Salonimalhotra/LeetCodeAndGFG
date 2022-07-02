// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int **dp=new int*[M+1];
	    for(int i=0;i<=M;i++){
	        dp[i]=new int[V+1];
	    }
	    // if we have to make 0 amount then minimum number of coins required are 0
	    for(int i=0;i<=M;i++){
	        dp[i][0]=0;
	    }
	    //if we have V amount to make and have 0 coins then there is no way thus we assign INT_MAX:
	    for(int j=1;j<=V;j++){
	        dp[0][j]=INT_MAX;
	    }
	    
	    for(int i=1;i<=M;i++){
	        for(int j=1;j<=V;j++){
	            if(coins[i-1]<=j){
	                int option1=dp[i][j-coins[i-1]];
	                if(option1!=INT_MAX){
	                    option1+=1;
	                }
	                int option2=dp[i-1][j];
	                dp[i][j]=min(option1,option2);
	            }
	            else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    if(dp[M][V]==INT_MAX){
	        return -1;
	    }
	    return dp[M][V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends