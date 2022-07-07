// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        // code here
        int * dp=new int [N];
        dp[0]=1;
        for(int i=1;i<N;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(abs(A[j]-A[i])==1){
                   if(dp[j]+1>dp[i]){
                       dp[i]=dp[j]+1;
                   }
                }
            }
        }
        
        int maxAns=INT_MIN;
        for(int i=0;i<N;i++){
            maxAns=max(maxAns,dp[i]);
        }
        return maxAns;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends