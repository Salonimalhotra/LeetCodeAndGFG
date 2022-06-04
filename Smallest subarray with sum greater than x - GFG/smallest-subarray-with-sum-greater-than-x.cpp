// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        //Brute force Approach-O(n^3)
        // int maxlen=INT_MAX;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         int len=0;
        //         int sum=0;
        //         for(int k=i;k<=j;k++){
        //             len++;
        //             sum+=arr[k];
        //         }
        //         if(sum>x){
        //             maxlen=min(len,maxlen);
        //         }
                
        //     }
        // }
        // return maxlen;
        int i=0;
        int j=0;
        int sum=0;
        int maxlen=INT_MAX;
        while(j<n){
            sum+=arr[j];
            if(sum<=x){
                j++;
            }
            else{
                maxlen=min(maxlen,j-i+1);
                while(sum>x && i<n){
                    // sum-=arr[i];
                    if(sum-arr[i]>x){
                        sum=sum-arr[i];
                        i++;
                    }
                    else{
                        break;
                    }
                }
                maxlen=min(maxlen,j-i+1);
                j++;
            }
        }
        maxlen=min(maxlen,j-i+1);
        return maxlen;
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