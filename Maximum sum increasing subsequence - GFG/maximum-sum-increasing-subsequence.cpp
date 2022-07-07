// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int * dp=new int[n];
	    int maxSum=INT_MIN;
	    dp[0]=arr[0];
	    maxSum=arr[0];
	    for(int i=1;i<n;i++){
	        dp[i]=arr[i];
	       for(int j=i-1;j>=0;j--){
	          if(arr[i]>arr[j]){
	              if(dp[j]+arr[i]>dp[i]){
	                  dp[i]=dp[j]+arr[i];
	                  
	              }
	          }
	          
	       }
	       maxSum=max(maxSum,dp[i]);
	    }
	    return maxSum;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends