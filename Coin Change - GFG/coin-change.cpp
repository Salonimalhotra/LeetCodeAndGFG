// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
     long long int helper(int S[],int m,int n){
        //  if(n==0){
        //      // if value to make is 0 then there is always one option to take no coin
        //      return 1;   
        //  }
        //  if(m==0 && n!=0){
        //      // if number of coins are zero then there are no ways to make up for the value n
        //      return 0;
        //  }
         
        //  if(S[m-1]<=n){
        //      long long int option1=helper(S,m,n-S[m-1]);
        //      long long int option2=helper(S,m-1,n);
        //      return option1+option2;
        //  }
        //  else{
        //      return helper(S,m-1,n);
        //  }
         long long int  **dp=new  long long int *[m+1];
        for(int i=0;i<=m;i++){
            dp[i]=new  long long int [n+1];
        }
        // i have i coins to make 0 value,there is always 1 way to do that ,take no coins
        for(int i=0;i<=m;i++){
            dp[i][0]=1;
        }
        // i have 0 coins to make a value ranging from 1 to j,so there is no way to do that
        for(int j=1;j<=n;j++){
            dp[0][j]=0;
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(S[i-1]<=j){
                    dp[i][j]=(dp[i-1][j]+dp[i][j-S[i-1]]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[m][n]; 
     }
     long long int count(int S[], int m, int n) {
         return helper(S,m,n);
     }
    //  long long int count(int S[], int m, int n) {
    //      long long int dp[m+1][n+1];
         
    //      for(int i=0;i<=m;i++){
    //       dp[i][0]=1;    
    //      }
    //      for(int j=1;j<=n;j++){
    //          dp[0][j]=0;
    //      }
    //      for(int i=1;i<=m;i++){
    //          for(int j=1;j<=n;j++){
    //              if(S[i-1]<=j){
    //                  dp[i][j]=dp[i-1][j]+dp[i][j-S[i-1]];
    //              }
    //              else{
    //                  dp[i][j]=dp[i-1][j];
    //              }
    //          }
    //      }
    //      return dp[m][n];
    //  }
    // long long int helper(int S[],int m,int n,long long int **dp){
    //     if(n==0){
    //         return 1;
    //     }
    //     if(m==0){
    //         return 0;
    //     }
    //     if(dp[m][n]!=-1){
    //         return dp[m][n];
    //     }
    //     //if we are taking the current coin;
    //     if(S[m-1]<=n){
    //     long long int x=helper(S,m,n-S[m-1],dp);
    //     long long int y=helper(S,m-1,n,dp);
    //     return dp[m][n]=x+y;
    //     }
    //     else{
    //         return  dp[m][n]=helper(S,m-1,n,dp);
    //     }
    // }
    // long long int count(int S[], int m, int n) {

    //     // code here.
    //       long long int **dp=new long long int*[m+1];
    //       for(int i=0;i<=m;i++){
    //       dp[i]=new long long int[n+1];
    //          for(int j=0;j<=n;j++){
    //           dp[i][j]=-1;
    //           }
    //      }
    //      return helper(S,m,n,dp);
    // }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends