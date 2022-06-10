// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMissing(int arr[], int n) {
        // code here
        int low=0;
        int high=n-1;
        int missing=-1;
        int diff=(arr[n-1]-arr[0])/n;
        
        while(low<=high){
            int mid=(low+(high-low)/2);
            if(mid+1<n && arr[mid+1]-arr[mid]!=diff){
                missing=arr[mid]+diff;
                break;
            }
            else if(mid-1>=0 && arr[mid]-arr[mid-1]!=diff){
                missing=arr[mid]-diff;
                break;
            }
            else if(arr[mid]==arr[0]+mid*diff){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return missing;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMissing(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends