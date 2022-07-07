// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.

class Solution{
    public:
    long long helper(int arr[],int i,int j,int n,int **dp){
        if(i>j){
            return 0;
        }
        else if(i==j){
            return arr[i];
        }
        else if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long int option1=arr[i]+min(helper(arr,i+1,j-1,n-2,dp),helper(arr,i+2,j,n-2,dp));
        long long int option2=arr[j]+min(helper(arr,i+1,j-1,n-2,dp),helper(arr,i,j-2,n-2,dp));
        dp[i][j]=max(option1,option2);
        return max(option1,option2);
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        int **dp=new int *[n];
        for(int i=0;i<n;i++){
            dp[i]=new int[n];
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        
        return helper(arr,0,n-1,n,dp);
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends