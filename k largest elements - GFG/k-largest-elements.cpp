// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
#include<queue>
#include<algorithm>
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue<int,vector<int>,greater<int>>pq;
	    for(int i=0;i<k;i++){
	        pq.push(arr[i]);
	    }
	    for(int j=k;j<n;j++){
	      if(arr[j]>pq.top()){
	          pq.pop();
	          pq.push(arr[j]);
	      }   
	   }
	   vector<int>ans;
	   while(pq.size()!=0){
	       ans.push_back(pq.top());
	       pq.pop();
	   }
	   reverse(ans.begin(),ans.end());
	   return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends