// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                count++;
            }
        }
        if(count==n || count==0){
            return 0;
        }
        int i=0;
        int j=0;
        int minSwaps=INT_MAX;
        int minAns=0;
        while(j<n){
            if(arr[j]>k){
                minAns++;
            }
            if(j-i+1<count){
                j++;
            }
            else if(j-i+1==count){
                minSwaps=min(minSwaps,minAns);
                if(arr[i]>k){
                    minAns--;
                    i++;
                }
                else{
                    i++;
                }
                j++;
            }
        }
        return minSwaps;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends