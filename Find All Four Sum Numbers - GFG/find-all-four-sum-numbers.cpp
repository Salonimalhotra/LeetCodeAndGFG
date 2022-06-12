// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++
#include<algorithm>
#include<set>
#include<vector>
class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        set<vector<int>>s;
        int n=arr.size();
        for(int i=0;i<arr.size()-3;i++){
            for(int j=i+1;j<arr.size()-2;j++){
                int i1=j+1;
                int j1=n-1;
                while(i1<j1){
                    if(arr[i]+arr[j]+arr[i1]+arr[j1]==k){
                        vector<int>ans1;
                        ans1.push_back(arr[i]);
                        ans1.push_back(arr[j]);
                        ans1.push_back(arr[i1]);
                        ans1.push_back(arr[j1]);
                        s.insert(ans1);
                        i1++;
                        j1--;
                    }
                    else if(arr[i]+arr[j]+arr[i1]+arr[j1]<k){
                        i1++;
                    }
                    else if(arr[i]+arr[j]+arr[i1]+arr[j1]>k){
                        j1--;
                    }
                }
            }
        }
        vector<vector<int>>finalAns;
        for(auto i:s){
            finalAns.push_back(i);
        }
        return finalAns;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends