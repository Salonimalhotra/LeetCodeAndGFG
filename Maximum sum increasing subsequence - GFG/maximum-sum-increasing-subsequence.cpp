//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int>dp(n,0);
	    int maxAns=INT_MIN;
	    for(int i=0;i<n;i++){
	        dp[i]=arr[i];
	        for(int j=i-1;j>=0;j--){
	            if(arr[i]>arr[j] && dp[j] + arr[i]>dp[i]){
	                dp[i]=dp[j] + arr[i];
	            }
	        }
	        maxAns=max(maxAns,dp[i]);
	    }
	    return maxAns;
	}  
};

//{ Driver Code Starts.
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