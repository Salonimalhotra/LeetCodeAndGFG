// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int minLen=INT_MAX;
        int i=0;
        int j=0;
        int sum=0;
        while(j<n){
            sum+=arr[j];
            if(sum<=x){
                j++;
            }
            else if(sum>x){
                minLen=min(minLen,j-i+1);
                while(sum-arr[i]>x){
                    sum-=arr[i];
                    i++;
                }
                minLen=min(minLen,j-i+1);
                j++;
            }
        }
        return minLen;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends