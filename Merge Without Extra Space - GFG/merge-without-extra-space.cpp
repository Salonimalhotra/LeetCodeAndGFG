// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int arr[n+m];
	    int k=0;
	    int i=0;
	    int j=0;
	    while(i<n && j<m){
	        if(arr1[i]<arr2[j]){
	            arr[k]=arr1[i];
	            k++;
	            i++;
	        }
	        else if(arr1[i]>arr2[j]){
	            arr[k]=arr2[j];
	            k++;
	            j++;
	        }
	        else if(arr1[i]==arr2[j]){
	            arr[k++]=arr1[i++];
	        }
	    }
	    while(i<n){
	        arr[k++]=arr1[i++];
	    }
	    while(j<m){
	        arr[k++]=arr2[j++];
	    }
	    i=0;
	    int t=0;
	    for(;i<n;i++){
	        arr1[t]=arr[i];
	        t++;
	    }
	    t=0;
	    for(;i<n+m;i++){
	        arr2[t]=arr[i];
	        t++;
	    }
	    return ;
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends