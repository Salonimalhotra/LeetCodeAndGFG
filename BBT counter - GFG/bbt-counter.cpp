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
        long long int ans[h+1];
        ans[0]=1;
        ans[1]=1;
        long long int mod=pow(10,9)+7;
        for(int i=2;i<=h;i++){
            long long int option1=ans[i-1]%mod;
            long long int option2=ans[i-2]%mod;
            
            long long int temp1=(option1*option1)%mod;
            long long int temp2=2*(option1*option2)%mod;
            ans[i]=(temp1+temp2)%mod;
        }
        
        return ans[h];
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