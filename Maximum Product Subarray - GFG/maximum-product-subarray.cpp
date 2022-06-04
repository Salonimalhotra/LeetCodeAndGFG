// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    //Brute force-O(n^3);
	   // long long maxProduct=INT_MIN;
	   //  for(int i=0;i<n;i++){
	   //      for(int j=i;j<n;j++){
	   //          long long  product=1;
	   //          for(int k=i;k<=j;k++){
	   //              product*=arr[k];
	   //          }
	   //          maxProduct=max(maxProduct,product);
	   //      }
	   //  }
	   //  return maxProduct;
	   long long  product=1;
	   long long  maxProduct=INT_MIN;
	   
	   for(int i=0;i<n;i++){
	       if(arr[i]!=0){
	           product*=arr[i];
	           maxProduct=max(maxProduct,product);
	       }
	       else{
	           product=1;
	           continue;
	       }
	      
	     }
	     
	   product=1;
	   for(int j=n-1;j>=0;j--){
	        if(arr[j]!=0){
	           product*=arr[j];
	           maxProduct=max(maxProduct,product);
	       }
	       else{
	           product=1;
	           continue;
	       }
	   }
	   return maxProduct;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends