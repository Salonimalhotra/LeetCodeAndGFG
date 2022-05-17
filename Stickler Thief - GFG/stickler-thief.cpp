// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int helper(int arr[],int i,int *dp){
        if(i<=0){
            return 0;
        }
        else if(i==1){
            return arr[0];
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int smallAns=arr[i-1]+helper(arr,i-2,dp);
        int smallAns1=helper(arr,i-1,dp);
        dp[i]=max(smallAns,smallAns1);
        return dp[i];
    }
    int FindMaxSum(int arr[], int n)
    {
        
        // Your code here
      
        int *dp=new int[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=-1;
        }
        
          return helper(arr,n,dp); 
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends