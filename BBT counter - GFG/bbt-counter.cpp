// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#include<cmath>
class Solution {
  public:
  
    long long int countBT(int h) { 
        // code here
        int mod=pow(10,9)+7;
        int * dp=new int[h+1];
        for(int i=0;i<=h;i++){
            dp[i]=0;
        }
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=h;i++){
            long long int x=dp[i-1];
            long long int y=dp[i-2];
            long long int option1=(x*x)%mod;
            long long int option2=(2*x*y)%mod;
            dp[i]=(option1+option2)%mod;
        }
        return dp[h];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends