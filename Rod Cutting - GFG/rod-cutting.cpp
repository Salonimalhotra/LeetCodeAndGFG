// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int helper(int price[],int length[],int n,int maxlen){
        // if(n==0 || maxlen==0){
        //     return 0;
        // }
        
        // if(length[n-1]<=maxlen){
        //     int option1=price[n-1]+helper(price,length,n,maxlen-length[n-1]);
        //     int option2=helper(price,length,n-1,maxlen);
        //     return max(option1,option2);
        // }
        
        // else{
        //     return helper(price,length,n-1,maxlen);
        // }
        
        int ** dp=new int *[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new int[n+1];
        }
        
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(length[i-1]<=j){
                    dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][n];
    }
    int cutRod(int price[], int n) {
        //code here
        // int **dp=new int*[n+1];
        // for(int i=0;i<=n;i++){
        //     dp[i]=new int[n+1];
        // }
        
        int * length=new int[n];
        for(int i=0;i<n;i++){
            length[i]=i+1;
        }
        
        return helper(price,length,n,n);
        
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends