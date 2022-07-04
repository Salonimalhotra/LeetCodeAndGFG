// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       int * dp=new int[n];
       dp[0]=1;
       int maxAns=1;
       for(int i=1;i<n;i++){
           int temp=1;
           for(int j=i-1;j>=0;j--){
               if(a[i]>a[j]){
                   temp=max(temp,dp[j]+1);
               }
           }
           dp[i]=temp;
           maxAns=max(maxAns,dp[i]);
       }
       
       return maxAns;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends