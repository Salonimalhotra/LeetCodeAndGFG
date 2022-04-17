// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        // code here
        if(n==0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        long long int a=0;
        long long int b=1;
        long long int c;
        int mid=pow(10,9)+7;
        for(int i=2;i<=n;i++){
            c=(a+b)%mid;
            a=b;
            b=c;
        }
        return c;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends