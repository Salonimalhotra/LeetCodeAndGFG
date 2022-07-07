// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int helper(int n,int k,int **dp){
        if(k==0 || k==1){
            return k;
        }
        else if(n==1){
            return k;
        }
        else if(n==0){
            return 0;
        }
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        int minAns=INT_MAX;
        for(int j=1;j<=k;j++){
            int option1=1+helper(n,k-j,dp);
            int option2=1+helper(n-1,j-1,dp);
            int tempAns=max(option1,option2);
            if(tempAns<minAns){
                minAns=tempAns;
            }
        }
        dp[n][k]=minAns;
        return dp[n][k];
    }
    int eggDrop(int n, int k) 
    {
        // your code here
         int **dp=new int *[n+1];
         for(int i=0;i<=n;i++){
             dp[i]=new int[k+1];
             for(int j=0;j<=k;j++){
                 dp[i][j]=-1;
             }
         }
         
         return helper(n,k,dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends