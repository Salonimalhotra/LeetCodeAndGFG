// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int pivot_index(int arr[],int n){
        if(arr[0]<arr[n-1]){
            return 0;
        }
        int p=-1;
        int start=0;
        int end=n-1;
        while(start<end){
            int mid=start+(end-start)/2;
            if(arr[mid]>=arr[0]){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        return start;
    }
	int findKRotation(int arr[], int n) {
	    // code here
	   
	    if(arr[0]<arr[n-1]){
	        return 0;
	    }
	    
	    int pivot=pivot_index(arr,n);
	    return pivot;
	    
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends