// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    bool ** subsetSum(int arr[],int n,int range){
        //dp table containing values
        bool ** dp=new bool *[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new bool[range+1];
        }
        
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int j=1;j<=range;j++){
            dp[0][j]=false;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=range;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
                    
                }
                else if(arr[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp;
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    bool ** dp=subsetSum(arr,n,sum);
	    
	    vector<int>ans;
	    
	    for(int j=0;j<=sum/2;j++){
	        if(dp[n][j]==true){
	            ans.push_back(j);
	        }
	    }
	    int min_diff=INT_MAX;
	    for(int i=0;i<ans.size();i++){
	        if(sum-2*ans[i]<min_diff){
	            min_diff=sum-2*ans[i];
	        }
	    }
	    return min_diff;
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends