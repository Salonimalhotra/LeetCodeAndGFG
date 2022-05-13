// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  int firstOcc(vector<int>&arr,int n,int k){
      int start=0;
      int end=n-1;
      int first=-1;
      
      while(start<=end){
          int mid=start+(end-start)/2;
          
          if(arr[mid]==k){
              first=mid;
              end=mid-1;
          }
          else if(arr[mid]<k){
              start=mid+1;
          }
          else {
              end=mid-1;
          }
      }
      return first;
  }
  
  int lastOcc(vector<int>&arr,int n,int k){
      int start=0;
      int end=n-1;
      int last=-1;
      
      while(start<=end){
          int mid=start+(end-start)/2;
          
          if(arr[mid]==k){
              last=mid;
              start=mid+1;
          }
          else if(arr[mid]<k){
              start=mid+1;
          }
          else {
              end=mid-1;
          }
      }
      return last;
  }
  
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        int first=firstOcc(arr,n,x);
        int last=lastOcc(arr,n,x);
        vector<int>ans;
        if(first==last && first==-1){
            ans.push_back(first);
            return ans;
        }
        ans.push_back(first);
        ans.push_back(last);
        return ans;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}
  // } Driver Code Ends