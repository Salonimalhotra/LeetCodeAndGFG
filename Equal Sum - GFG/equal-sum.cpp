// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string equilibrium(int *arr, int n) {
        // code here
        // int prefixArray[n];
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            // prefixArray[i]=sum;
        }
        
        // int suffixArray[n];
        //  sum=0;
        // for(int i=n-1;i>=0;i--){
        //   sum+=arr[i];
        //   suffixArray[i]=sum;
        // }
        
        bool check=false;
        int leftSum=0;
        for(int i=0;i<n;i++){
           if(leftSum==sum-arr[i]){
               check=true;
               break;
           }
           leftSum+=arr[i];
           sum=sum-arr[i];
        }
        if(check==true){
            
            return "YES";
        }
        
        else{
            return "NO";
        }
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
        auto ans = ob.equilibrium(a, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends