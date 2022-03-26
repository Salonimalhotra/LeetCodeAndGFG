// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        if(n==0 || n==1){
            return 0;
        }
        priority_queue<long ,vector<long >,greater<long long >>minHeap;
        for(long long i=0;i<n;i++){
            minHeap.push(arr[i]);
        }
        
        long long ans=0;
        while(minHeap.size()!=0){
            long long x=minHeap.top();
            minHeap.pop();
            long long y=minHeap.top();
            minHeap.pop();
            long long cost=x+y;
            ans+=cost;
            if(minHeap.size()!=0){
                minHeap.push(cost);
            }
            else{
                break;
            }
        }
        
        return ans;
        
        
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends