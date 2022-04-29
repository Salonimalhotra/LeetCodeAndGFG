// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int helper(int S[],int m,int n,long long int **dp){
        if(n==0){
            return 1;
        }
        if(m==0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        //if we are taking the current coin;
        if(S[m-1]<=n){
        long long int x=helper(S,m,n-S[m-1],dp);
        long long int y=helper(S,m-1,n,dp);
        return dp[m][n]=x+y;
        }
        else{
            return  dp[m][n]=helper(S,m-1,n,dp);
        }
    }
    long long int count(int S[], int m, int n) {

        // code here.
          long long int **dp=new long long int*[m+1];
          for(int i=0;i<=m;i++){
           dp[i]=new long long int[n+1];
             for(int j=0;j<=n;j++){
               dp[i][j]=-1;
              }
         }
         return helper(S,m,n,dp);
    }
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